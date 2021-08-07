#include "servidor.h"
#include "usuario.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

Servidor::Servidor(int _id, string _nome){
    this->usuarioDonoId = _id;
    this->nome = _nome;
}
int Servidor::getDonoId(){
    return this->usuarioDonoId;
}

string Servidor::getNome(){
    return this->nome;
}

void Servidor::setDescricao(string _descricao){
    this->descricao = _descricao;
}
string Servidor::getDescricao(){
    return this->descricao;
}

void Servidor::setCodigo(string _codigo){
    this->codigoConvite = _codigo;
}
string Servidor::getCodigo(){
    return this->codigoConvite;
}

void Servidor::addParticipante(int _id){
    participantesIDs.push_back(_id);
}
bool Servidor::checkParticipante(int _id){
    for(int i=0; i<participantesIDs.size(); i++)
        if(participantesIDs.begin()[i] == _id)
            return true;
    return false;
}
void Servidor::delParticipante(int _id){
    for(int i=0; i<participantesIDs.size(); i++)
        if(participantesIDs.begin()[i] == _id)
            participantesIDs.erase(participantesIDs.begin()+i);
}

void Servidor::printCanais(){
    if(canaisTexto.size() == 0)
        cout<<"Não há canais para exibir";
    for(int i=0; i<canaisTexto.size(); i++){
        if(i>0)
            cout<<endl;
        cout<<canaisTexto[i].getNome();
    }
}

void Servidor::addCanal(string nome){
    CanalTexto temp(nome);
    canaisTexto.push_back(temp);
}

bool Servidor::checkCanal(string nome){
    for(int i=0; i<canaisTexto.size(); i++)
        if(canaisTexto[i].getNome() == nome)
            return true;
    return false;    
}

void Servidor::addMensagem_Server(int id, const string mensagem, string canal, string datahora){
    for(int i=0; i<canaisTexto.size(); i++)
        if(canaisTexto[i].getNome() == canal)
            canaisTexto[i].addMensagem(id, mensagem, datahora);
}

void Servidor::printMensagens_Server(string canal, vector<Usuario>* usuarios){
    for(int i=0; i<canaisTexto.size(); i++)
        if(canaisTexto[i].getNome() == canal)
            canaisTexto[i].printMensagens(usuarios);
}