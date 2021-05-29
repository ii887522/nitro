'use strict'

import fsExtra from 'fs-extra'
import archiver from 'archiver'
import octokitRequest from '@octokit/request'

const { ensureDirSync, createWriteStream, copy, remove, readFile } = fsExtra
const { request } = octokitRequest

const version = process.argv[2]
const accessToken = process.argv[3]

async function bundleInclude() {
  ensureDirSync(`libs/nitro-${version}/include/nitro/`)
  return copy('nitro/src/main/', `libs/nitro-${version}/include/nitro/`, { recursive: true, filter: (src, dest) => {
    return !src.endsWith('.cpp')
  } })
}

async function bundleX86Debug() {
  ensureDirSync(`libs/nitro-${version}/lib/x86/Debug/`)
  return copy('nitro/Debug/nitro.lib', `libs/nitro-${version}/lib/x86/Debug/nitro.lib`)
}

async function bundleX86Release() {
  ensureDirSync(`libs/nitro-${version}/lib/x86/Release/`)
  return copy('nitro/Release/nitro.lib', `libs/nitro-${version}/lib/x86/Release/nitro.lib`)
}

async function bundleX64Debug() {
  ensureDirSync(`libs/nitro-${version}/lib/x64/Debug/`)
  return copy('nitro/x64/Debug/nitro.lib', `libs/nitro-${version}/lib/x64/Debug/nitro.lib`)
}

async function bundleX64Release() {
  ensureDirSync(`libs/nitro-${version}/lib/x64/Release/`)
  return copy('nitro/x64/Release/nitro.lib', `libs/nitro-${version}/lib/x64/Release/nitro.lib`)
}

async function bundleX86() {
  return Promise.all([
    bundleX86Debug(),
    bundleX86Release()
  ])
}

async function bundleX64() {
  return Promise.all([
    bundleX64Debug(),
    bundleX64Release()
  ])
}

async function bundleLib() {
  return Promise.all([
    bundleX86(),
    bundleX64()
  ])
}

async function bundle() {
  return Promise.all([
    bundleInclude(),
    bundleLib()
  ])
}

async function zip() {
  const archive = archiver('zip', { zlib: { level: 9 } })
  archive.on('warning', err => {
    if (err.code == 'ENOENT') console.log(err)
    else throw err
  }).on('error', err => {
    throw err
  }).pipe(createWriteStream(`libs/nitro-${version}.zip`))
  return archive.directory(`libs/nitro-${version}/`, `nitro-${version}/`).finalize()
}

async function publish() {
  const result = await request('POST /repos/{owner}/{repo}/releases', {
    headers: {
      authorization: `token ${accessToken}`
    },
    owner: 'ii887522',
    repo: 'nitro',
    tag_name: `v${version}`,
    name: `${version}`
  })
  return request('POST /repos/{owner}/{repo}/releases/{release_id}/assets{?name,label}', {
    headers: {
      authorization: `token ${accessToken}`,
      'content-type': 'application/zip'
    },
    baseUrl: 'https://uploads.github.com',
    owner: 'ii887522',
    repo: 'nitro',
    release_id: result.data.id,
    name: `nitro-${version}.zip`,
    data: await readFile(`libs/nitro-${version}.zip`)
  })
}

(async () => {
  await bundle()
  await zip()
  await publish()
  remove('libs/')
})()
