#include "usuario.h"

using namespace std;

Usuario::Usuario(int _id, string _nome, string _senha, string _email){
    this->id = _id;
    this->nome = _nome;
    this->senha = _senha;
    this->email = _email;
}

int Usuario::getId(){
    return this->id;
}

string Usuario::getNome(){
    return this->nome;
}

string Usuario::getEmail(){
    return this->email;
}

bool Usuario::checkLogin(string _email, string _senha){
    if(this->email == _email && this->senha == _senha)
        return true;
    return false;
}