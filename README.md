# Projeto 2: Concordo 2.0 (Persistencia de dados)
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
Você roda o programa gerado e logo depois digitar os comandos seguidos de ENTER
```console
./concordo
```

## Organização dos arquivos
A organização dos arquivos foi divido em 2 partes (Usuários e Servidores) e estão alocadas na pasta data:
#### Usuários
O arquivo **usuarios.txt** armazena os dados dos usuarios a cada 3 linhas contendo: email, senha e nome.
```
{Email}
{Senha}
{Nome}
```
#### Servidores
O arquivo **servidores.txt** armazena os dados de quantidade fixa dos servidores a cada 4 linhas contendo: id do dono, nome, descrição e código de convite. (
Há tambem o arquivo, no mesmo padrão, **copia_servidores.txt** com fim de auxiliar a remoção de servidores.)
```
{ID do dono do servidor}
{Nome do servidor}
{Descrição}
{Código de convite}
```
Ainda sobre os servidores há a pasta **canais_servidores** com os seguinte arquivos referentes aos canais e suas mensagens:
* {nome do servidor}.txt
  * Com os nomes dos canais um por linha.
     ```
    {Canal 1}
    {Canal 2}
    .
    .
    .
    ```
* {nome do servidor}_{nome do canal}.txt.txt
  * Com as mensagens sendo registrada cada em 3 linhas no formato:
    ```
    {ID do autor}
    {Mensagem}
    {Data e hora no formato <dd/mm/AAAA - HH:MM>}
    ```
## Limitações desta versão
* Remoção de arquivos
* ...

## Autor

Angelo Gustavo Souza Marinho Morais de Sales -
[GitHub](https://github.com/AngeloGustavo)

## Contato

Angelo Gustavo Souza Marinho Morais de Sales -
*<angelo.sales.703@ufrn.edu.br>*

Link do projeto: [https://github.com/AngeloGustavo/ConcordoV2.git](https://github.com/AngeloGustavo/ConcordoV2.git)
