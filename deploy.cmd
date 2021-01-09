docker run --rm --name nitro_bundler -w C:\nitro -v %CD%:C:\nitro mcr.microsoft.com/windows/servercore:20H2 cmd /c mkdir libs && cd libs && mkdir nitro && cd nitro && mkdir include && cd include && xcopy ..\..\..\nitro\src\main\ .\ /s && cd .. && mkdir lib && cd lib && mkdir x86 && cd x86 && mkdir Debug && cd Debug && copy ..\..\..\..\..\nitro\Debug\nitro.lib .\ && cd .. && mkdir Release && cd Release && copy ..\..\..\..\..\nitro\Release\nitro.lib .\ && cd .. && cd .. && mkdir x64 && cd x64 && mkdir Debug && cd Debug && copy ..\..\..\..\..\nitro\x64\Debug\nitro.lib .\ && cd .. && mkdir Release && cd Release && copy ..\..\..\..\..\nitro\x64\Release\nitro.lib .\ && cd .. && cd .. && cd .. && cd .. && cd ..
docker run --rm --name nitro_zipper -w C:\nitro\libs -v %CD%\libs:C:\nitro\libs kiazhi/nanoserver.7-zip:1709-18.05 7z a nitro.zip nitro\
docker run --rm --name nitro_publisher -v %CD%\libs:C:\nitro\libs stefanscherer/curl-windows:7.58.0 --header "PRIVATE-TOKEN: %1" --upload-file C:\nitro\libs\nitro.zip https://gitlab.com/api/v4/projects/23530641/packages/generic/nitro/1.0.0/nitro.zip
docker run --rm --name nitro_cleaner -w C:\nitro -v %CD%:C:\nitro mcr.microsoft.com/windows/servercore:20H2 cmd /c rmdir libs /s /q
