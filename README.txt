Trabalho de Software Básico - Montador do assembly inventado

Pedro Nogueira - 14/0065032
Gabriel Moretto - 15/0154917
UnB - 2022/1


------------------------------------------------------------------------------------------------------------------------


Seção do não quero ler tudo

Sugestão de uso:

make clean && make debug
./program.exe arq1.o arq2.o


------------------------------------------------------------------------------------------------------------------------


Como rodar

O projeto usa makefile (dentro da pasta ./code), e ele tem algumas instruções:

make clean - limpa os arquivos compilados do projeto
make debug - compila todos os arquivos do projeto em modo debug (devagar) - gera um program.exe
make release - compila todos os arquivos do projeto sem debug (e mais rápido) - gera um program.exe
make cppcheck - usa o cppcheck em todos os arquivos do projeto
  * está QUASE 100% limpo - sem warning NENHUM na compilação, mas tem 1 tipo de warning de uso que o cppcheck recomendou que não soubemos resolver...
make help - mostra todas as instruções do make que criei aqui (essas mesmas instruções)

Para executar, ele faz como foi pedido no trabalho:
Primeiro o arquivo que teria a "main" do projeto e depois o segundo arquivo a ser ligado.


------------------------------------------------------------------------------------------------------------------------


Git

São dois projetos, cada um em seu próprio repositório git:
https://github.com/bananahell/Trabalho-SB-Montador - git do pré-processador e montador
https://github.com/GabrielCMoretto/Trabalho-SB-Ligador - git do ligador


------------------------------------------------------------------------------------------------------------------------


Diretório

Na root aqui tem
  .gitignore para não commitar tudo para o git,
  os READMEs, tanto esse quanto o que é mostrado no git,
  a pasta .vscode com configurações do vscode,
  e a pasta code, que tem todo o código, o makefile, os assemblies de exemplo, e o executável.

Na pasta ./code tem
  makefile que é onde compila o projeto com todas as instruções ditas lá em cima
  program.exe que é o executável gerado ao compilar o projeto
  pastas src e include que têm respectivamente os .cpp e os .h do projeto
  codr.o que é o arquivo de saída do projeto, podendo ser rodado com o simulador do professor!
  simulador e simulador.exe que são os simuladores dados pelo professor
  pastas dep e bin, geradas depois de compilar o projeto, têm os objetos e deps compilados


------------------------------------------------------------------------------------------------------------------------


Versão do g++

$ g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/9/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:hsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.4.0-1ubuntu1~20.04.1' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-9-Av3uEd/gcc-9-9.4.0/debian/tmp-nvptx/usr,hsa --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)

g++ usado no WSL2 no Windows com sistema operacional Ubuntu
código feito no VSCode

