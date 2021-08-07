#include "canaltexto.h"
#include "mensagem.h"
#include "usuario.h"

#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

CanalTexto::CanalTexto(string _nome){
    this->nome = _nome;
}

string CanalTexto::getNome(){
    return this->nome;
}

void CanalTexto::addMensagem(int id, const string mensagem, string datahora){
    Mensagem temp(datahora, id, mensagem);
    mensagens.push_back(temp);
}

void CanalTexto::printMensagens(vector<Usuario> *usuarios){
    if(mensagens.size() == 0)
        cout<<"Sem mensagens para exibir";
    for(int i=0; i<mensagens.size(); i++){
        if(i>0)
            cout<<endl;
        for(auto itr=usuarios->begin(); itr!=usuarios->end(); ++itr)
            if(itr->getId() == mensagens[i].getEnviadaPor()){
                cout<<itr->getNome()<<mensagens[i].getDataHora()<<": "<<mensagens[i].getConteudo();
                break;
            }
        
    }
}