#include "mensagem.h"

#include <iostream>
#include <string>

using namespace std;

Mensagem::Mensagem(string _dataHora, int _enviadaPor, string _conteudo){
    this->dataHora = _dataHora;
    this->enviadaPor = _enviadaPor;
    this->conteudo = _conteudo;
}

string Mensagem::getDataHora(){
    return this->dataHora;
}

int Mensagem::getEnviadaPor(){
    return this->enviadaPor;
}
        
string Mensagem::getConteudo(){
    return this->conteudo;
}