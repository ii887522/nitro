python -m pip install virtualenv
virtualenv env
source env/bin/activate && python -m pip install cpplint && source env/bin/deactivate && docker run --rm --name nitro_installer -w C:/nitro -v $PWD:C:/nitro nitro-custom-node ncu.cmd -u && npm.cmd install
