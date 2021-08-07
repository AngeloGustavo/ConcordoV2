# Projeto 2: Concordo
Clone do Discord, para humanos mais civilizados.

## O que é o Concordo?
Um sistema com recursos similares ao Discord, mas que funciona somente em modo texto e sem recursos de
rede. 

## Como compilar o projeto
Na pasta do projeto realize os próximos comandos para compilar o programa com cmake
```console
mkdir build
cd build
cmake ..
cmake --build .
```

## Como executar o projeto
Você pode rodar o programa gerado e logo depois digitar os comandos seguidos de ENTER
```console
./concordo
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão
```console
./concordo < script.txt
```
## Como executar o conjunto dos testes
### Para executar todas funcionalidades do sistema sem erros e com os erros execute os seguintes comandos:
Teste 1 (Todos comandos sem erro)
```console
./concordo < ../data/teste1.txt
``` 
Teste 2 (Erros de Usuario)
```console
./concordo < ../data/teste2.txt
```
Teste 3 (Erros de Servidor) 
```console
./concordo < ../data/teste3.txt
```
Teste 4 (Erros de CanalTexto) 
```console
./concordo < ../data/teste4.txt
```
Teste 5 (Erros de Mensagem) 
```console
./concordo < ../data/teste5.txt
```

## Autor

Angelo Gustavo Souza Marinho Morais de Sales -
[GitHub](https://github.com/AngeloGustavo)

## Contato

Angelo Gustavo Souza Marinho Morais de Sales -
*<angelo.sales.703@ufrn.edu.br>*

Link do projeto: [https://github.com/JulioMelo-Classes/trabalho-2-AngeloGustavo.git](https://github.com/JulioMelo-Classes/trabalho-2-AngeloGustavo.git)
