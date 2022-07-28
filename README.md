# Trabalho de Software Básico - Montador do assembly inventado

Pedro Nogueira - 14/0065032  
Gabriel Moretto - 15/0154917  
UnB - 2022/1  

## Como rodar (IMPORTANTE!!!)

O projeto usa makefile, e para compilar todos os arquivos do projeto basta usá-lo.  
As instruções faladas aqui agora podem ser checadas ao mandar o comando ```make help``` no terminal na altura do makefile (dentro da pasta code).  
Uma sugestão de como usá-lo é mandando os comandos:  
```make clean && make debug```  
ou  
```make clean && make release```  
A diferença está só em como compilar os arquivos, o primeiro estando em modo de teste e o segundo em um modo mais rápido de release. O comando ```make clean``` simplesmente apaga os arquivos .o e .d gerados.  

Depois de compilado o projeto, roda ele com  
```./program.exe arq1.o arq2.o```  
Os argumentos arq1 e arq2 são respectivamente o arquivo de "main" do programa e o segundo arquivo a ser ligado. O arquivo de saída (codr.o) é sempre salvo dentro da própria pasta code.  

## Estrutura do projeto

### ./code

A pasta code tem os códigos, o executável (.exe), o simulador do professor (simulador e simulador.exe), e os códigos de entrada e saída assembly (os .o e codr.o).  

### ./code/src | ./code/include

As pastas src e include possuem os códigos em C++ (src) e os .h (include).  

## Sugestão de uso do projeto

Dentro da pasta code do projeto do montador existem vários códigos em assembly que servem para testar o projeto. Dentre eles, alguns precisam ser ligados, então depois de montá-los, você traz os .o gerados para esse projeto e os liga aqui. Lá existem os exemplos:  
- ```fat_mod_A.asm``` ligado com ```fat_mod_B.asm``` escrevem na tela o fatorial de um número dado de entrada;  
- ```collatz.asm``` ligado com ```even_or_odd.asm``` escreve na tela a [conjectura de Collatz](https://www.youtube.com/watch?v=094y1Z2wpJg) de um número dado de entrada (even_or_odd.asm só funciona se ligado com collatz.asm, mas nele sozinho há a lógica para descobrir se um número é par ou ímpar).  

## Introdução

A matéria de Software Básico na UnB ensina o conceito de softwares de sistema e sobre suas aplicações a partir somente do hardware.  
Esse trabalho consiste em colocar em prática esses conceitos implementando uma linguagem assembly inventada.  

## Assembly inventado

Professores da UnB, para facilitar o ensino da matéria de Software Básico, resolveram criar uma linguagem assembly extremamente simples e Turing completa, e é o leitor dessa linguagem que foi feito nesse projeto. Somente existe 1 registrador, o acumulador (ACC), enquanto todo o resto da lógica roda na própria memória.  

Para ler esse assembly, o código precisa primeiro ser montado. No caso de haver mais de um módulo no código assembly, os .o gerados precisam ainda também ser ligados.  

Os .o que precisam ser ligados contém as tabelas de definição e uso do módulo e o binário não ligado. O ligador pega as informações de todas as tabelas de definição de todos os módulos e cria uma tabela global de definição. Depois ele pega o binário não ligado de cada módulo e o escreve no arquivo executável de saída, se atentando a sua tabela de uso e a quais endereços são absolutos (opcodes, SPACE, e CONST) ou relativos (memória). No final, o arquivo executável gerado finalmente está pronto para ser testado no simulador do professor.  

Existem nesse projeto 14 instruções, e outras diretivas de organização do código.  

### Instruções

Os opcodes das instruções, assim como os endereços das labels, todos ocupam somente 1 endereço, o que facilita muito na contagem dos endereços utilizados pelas linhas, dado assim então o tamanho da instrução. As instruções são:  
| Instrução      | Opcode | Tamanho | Ação                      |
| -------------- | ------ | ------- | ------------------------- |
| ADD            | 1      | 2       | ACC <- ACC + mem(OP)      |
| SUB            | 2      | 2       | ACC <- ACC - mem(OP)      |
| MULT           | 3      | 2       | ACC <- ACC x mem(OP)      |
| DIV            | 4      | 2       | ACC <- ACC ÷ mem(OP)      |
| JMP            | 5      | 2       | PC <- OP                  |
| JMPN           | 6      | 2       | Se ACC < 0 então PC <- OP |
| JMPP           | 7      | 2       | Se ACC > 0 então PC <- OP |
| JMPZ           | 8      | 2       | Se ACC = 0 então PC <- OP |
| COPY           | 9      | 3       | mem(OP2) <- mem(OP1)      |
| LOAD           | 10     | 2       | ACC <- mem(OP)            |
| STORE          | 11     | 2       | mem(OP) <- ACC            |
| INPUT          | 12     | 2       | mem(OP) <- entrada        |
| OUTPUT         | 13     | 2       | saída <- mem(OP)          |
| STOP           | 14     | 1       | Suspende a execução       |

### Demais diretivas

Existem mais algumas diretivas implementadas que servem somente para organização do código. Elas são:  
- ```SPACE``` forma de criar variáveis na memória, e é indicado por um zero no código objeto  
- ```CONST``` forma de criar constantes na memória, e é indicado pelo próprio valor no código objeto  
