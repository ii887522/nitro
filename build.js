'use strict'

import { options, dependencies, file } from '@ii887522/packify'

options.outDirPath = 'libs/'
options.x86DllOutDirPaths = []
options.x64DllOutDirPaths = []

dependencies(() => {
  file('https://github.com/catchorg/Catch2/releases/download/v2.13.6/catch.hpp')
})
