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

void CanalTexto::addMensagem(int id, const string mensagem){
    Mensagem temp(this->HoraData(), id, mensagem);
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

string CanalTexto::HoraData(){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string ano, mes, dia, hor, min;
    stringstream ss;

    ss << 1900 + ltm->tm_year;  
    ss >> ano; 
    ss.clear();

    ss << setw(2) << setfill('0') << 1 + ltm->tm_mon;
    ss >> mes;
    ss.clear();

    ss << setw(2) << setfill('0') << ltm->tm_mday;
    ss >> dia;
    ss.clear();

    ss << setw(2) << setfill('0') << ltm->tm_hour;
    ss >> hor;
    ss.clear();

    ss << setw(2) << setfill('0') << ltm->tm_min;
    ss >> min;
    
    return "<"+dia+"/"+mes+"/"+ano+" - "+hor+":"+min+">";
}