python -m pip install virtualenv
virtualenv env
env\Scripts\activate && python -m pip install cpplint && env\Scripts\deactivate && docker run --rm --name nitro_installer -w C:\nitro -v %CD%:C:\nitro nitro-custom-node ncu.cmd -u && npm.cmd install
