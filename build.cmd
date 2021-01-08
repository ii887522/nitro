docker run --rm --name nitro_debug_x86_builder -w C:\nitro -v %CD%:C:\nitro ms-build-tools msbuild C:\nitro\nitro\nitro.sln /p:Configuration=Debug /p:Platform=x86
docker run --rm --name nitro_debug_x64_builder -w C:\nitro -v %CD%:C:\nitro ms-build-tools msbuild C:\nitro\nitro\nitro.sln /p:Configuration=Debug /p:Platform=x64
docker run --rm --name nitro_release_x86_builder -w C:\nitro -v %CD%:C:\nitro ms-build-tools msbuild C:\nitro\nitro\nitro.sln /p:Configuration=Release /p:Platform=x86
docker run --rm --name nitro_release_x64_builder -w C:\nitro -v %CD%:C:\nitro ms-build-tools msbuild C:\nitro\nitro\nitro.sln /p:Configuration=Release /p:Platform=x64
