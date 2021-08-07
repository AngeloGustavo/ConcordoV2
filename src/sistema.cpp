#include "sistema.h"
#include "usuario.h"
#include "servidor.h"
#include "mensagem.h"
#include "canaltexto.h"

#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
/* COMANDOS */
string Sistema::quit() {
  return "Saindo do Concordo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
  for(int i=0; i<this->usuarios.size(); i++)
    if(this->usuarios[i].getEmail() == email)
      return "Usuário já existe!";
  Usuario temp(this->usuarios.size(), nome, senha, email);
  usuarios.push_back(temp);

  ofstream myfile;
  myfile.open("../data/usuarios.txt",fstream::app);
  char ch;
  myfile << email <<endl;
  myfile << senha <<endl;
  myfile << nome <<endl;
  myfile.close();

  return "Criando usuário "+temp.getNome()+" ("+temp.getEmail()+")\nUsuário Criado";
}
string Sistema::login(const string email, const string senha) {
  for(int i=0; i<this->usuarios.size(); i++)
    if(usuarios[i].checkLogin(email, senha) == true){
      this->usuariosLogados.insert({this->usuarios[i].getId(), {"",""}});
      stringstream ss;
      string id;
      ss << this->usuarios[i].getId();
      id = ss.str();
      return "Logado como "+this->usuarios[i].getEmail()+" (ID: "+id+")";
    }
  return "Senha ou usuário inválidos!";
}

string Sistema::disconnect(int id) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      usuariosLogados.erase(id);
      return "Desconectando usuário "+this->usuarios[id].getEmail();       
    }
  return "Não está conectado";
}

string Sistema::create_server(int id, const string nome) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      for(int i=0; i<this->servidores.size(); i++)
        if(this->servidores[i].getNome() == nome)
          return "Servidor com esse nome já existe";

      Servidor temp(id, nome);
      servidores.push_back(temp);

      ofstream myfile("../data/servidores.txt",fstream::app);
      myfile << id <<endl;
      myfile << nome <<endl;
      myfile << endl;
      myfile << endl;
      myfile.close();

      ofstream myfile2("../data/canais_servidores/"+nome+".txt",fstream::app);
      myfile2.close();

      return "Servidor criado"; 
    }

  return "Usuário não conectado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  this->copy_servers();

  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      for(int i=0; i<servidores.size(); i++)
        if(servidores[i].getNome() == nome){
          if(servidores[i].getDonoId() == id){
            servidores[i].setDescricao(descricao);

            string idA,nomeA,descA,codeA;
            ofstream myfile ("../data/servidores.txt");
            ifstream myfileC("../data/copia_servidores.txt");
            if (myfileC.is_open()){ 
              while(getline (myfileC,idA)){
                myfile << idA <<endl;

                getline (myfileC,nomeA);
                myfile << nomeA <<endl;

                if(servidores[i].getNome() == nomeA){
                  getline (myfileC,descA);
                  myfile << descricao <<endl;
                }else{
                  getline (myfileC,descA);
                  myfile << descA <<endl;
                }

                getline (myfileC,codeA);
                myfile << codeA <<endl;
              }
              myfile.close();
              myfileC.close();
              this->copy_servers();
            }
            return "Descrição do servidor ‘"+nome+"’ modificada!";
          }else
            return "Você não pode alterar a descrição de um servidor que não foi criado por você";
        }
      return "Servidor ‘"+nome+"’ não existe";
    }
  return "Usuário não conectado";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){  
      for(int i=0; i<servidores.size(); i++)
        if(servidores[i].getNome() == nome){
          if(servidores[i].getDonoId() == id){
            servidores[i].setCodigo(codigo);

            string idA,nomeA,descA,codeA;
            ofstream myfile ("../data/servidores.txt");
            ifstream myfileC("../data/copia_servidores.txt");
            if (myfileC.is_open()){ 
              while(getline (myfileC,idA)){
                myfile << idA <<endl;

                getline (myfileC,nomeA);
                myfile << nomeA <<endl;

                getline (myfileC,descA);
                myfile << descA <<endl;

                if(servidores[i].getNome() == nomeA){
                  getline (myfileC,codeA);
                  myfile << codigo <<endl;
                }else{
                  getline (myfileC,codeA);
                  myfile << codeA <<endl;
                }
              }
              myfile.close();
              myfileC.close();
              this->copy_servers();
            }
            if(codigo != "")
              return "Código de convite do servidor ‘"+nome+"’ modificado!";
            else
              return "Código de convite do servidor ‘"+nome+"’ removido!";
          }else
            return "Você não pode alterar o codigo de convite de um servidor que não foi criado por você";
        }
      return "Servidor ‘"+nome+"’ não existe";
    }
  return "Usuário não conectado";
}

string Sistema::list_servers(int id) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      if(servidores.size() == 0)
        return "Não há servidores no sistema";
      for(int i=0; i<servidores.size(); i++){
        if(i>0)
          cout<<endl;
        cout<<servidores[i].getNome();
      }
      return "";
    }
  return "Usuário não conectado";
}

string Sistema::remove_server(int id, const string nome) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      for(int i=0; i<servidores.size(); i++)
        if(nome == servidores[i].getNome()){
          if(servidores[i].getDonoId() == id){
            for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
              if((itr->second).first == nome)
                itr->second = {"",""};
            servidores.erase(servidores.begin() + i);
            return "Servidor ‘"+nome+"’ removido";
          }else
            return "Você não é o dono do servidor ‘"+nome+"’";
        }
      return "Servidor ‘"+nome+"’ não encontrado";
    }
  return "Usuário não logado";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      if((itr->second).first != "")
        return "Usuário ja está em um servidor";
      for(int i=0; i<servidores.size(); i++)
        if(servidores[i].getNome() == nome){
          if(servidores[i].getDonoId() == id || servidores[i].getCodigo() == "" || servidores[i].getCodigo() == codigo){
            /*if(!(servidores[i].checkParticipante(id))){
              servidores[i].addParticipante(id);
              
              ofstream myfile("../data/ids_servidores/ids_"+nome+".txt",fstream::app);
              int iid;
              stringstream ss;  
              ss << id;  
              ss >> iid; 
              myfile << iid <<endl;
              myfile.close();
            }*/
            servidores[i].addParticipante(id);
            itr->second = {servidores[i].getNome(),""};
            return "Entrou no servidor com sucesso";
          }else if(codigo == "")
            return "Servidor requer código de convite";
          else 
            return "Código de convite errado";
        }
      return "Servidor ‘"+nome+"’ não encontrado";
    }
  return "Usuário não conectado";
}

string Sistema::leave_server(int id, const string nome) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      for(int i=0; i<servidores.size(); i++)
        if(servidores[i].getNome() == nome){
          if(nome == (itr->second).first){
            servidores[i].delParticipante(id);
            itr->second = {"",""};
            return "Saindo do servidor ‘"+nome+"’";
          }else if((itr->second).first == "")
            return "Você não está visualizando nenhum servidor";
          else
            return "Você não está nesse servidor";
        }
      return "Servidor ‘"+nome+"’ não encontrado";
    }
  return "Usuário não conectado";
}

string Sistema::list_participants(int id) {
  bool primeiro = true;
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      if((itr->second).first == "")
        return "Você não está em um servidor";
      for(auto itr2=usuariosLogados.begin(); itr2!=usuariosLogados.end(); ++itr2)
        if((itr->second).first == (itr2->second).first){
          if(primeiro == true)
            primeiro = false;
          else
            cout<<endl;
          for(int i=0; i<usuarios.size(); i++)
            if(usuarios[i].getId() == itr2->first)
              cout<<usuarios[i].getNome();
        }
      return "";
    }
  return "Usuário não conectado";
}

string Sistema::list_channels(int id) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id)
      for(int i=0; i<servidores.size(); i++)
        if(servidores[i].getNome() == (itr->second).first){
          servidores[i].printCanais();
          return "";
        }
  return "Usuário não conectado";
}

string Sistema::create_channel(int id, const string nome) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id)
      for(int i=0; i<servidores.size(); i++)
        if(servidores[i].getNome() == (itr->second).first){
          if(servidores[i].checkCanal(nome))
            return "Canal de texto ‘"+nome+"’ já existe!";

          ofstream myfile("../data/canais_servidores/"+servidores[i].getNome()+"_"+nome+".txt",fstream::app);
          myfile.close();
          ofstream myfile2("../data/canais_servidores/"+servidores[i].getNome()+".txt",fstream::app);
          myfile2 << nome <<endl;
          myfile2.close();
        
          servidores[i].addCanal(nome);
          return "Canal de texto ‘"+nome+"’ criado";
        }
  return "Usuário não conectado";
}

string Sistema::enter_channel(int id, const string nome) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id)
      for(int i=0; i<servidores.size(); i++)
        if(servidores[i].getNome() == (itr->second).first){
          bool bol = servidores[i].checkCanal(nome);
          if(bol == false)
            return "Canal ‘"+nome+"’ não existe";
          (itr->second).second = nome;
          return "Entrou no canal ‘"+nome+"’";         
        }
  return "Usuário não conectado";
}

string Sistema::leave_channel(int id) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      (itr->second).second = "";
      return "Saindo do canal";
    }
  return "Usuário não conectado";
}

string Sistema::send_message(int id, const string mensagem) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      if((itr->second).second == "")
        return "Você não está em um canal";
      for(int i=0; i<servidores.size(); i++)
        if(servidores[i].getNome() == (itr->second).first){
          servidores[i].addMensagem_Server(id, mensagem, (itr->second).second);

          ofstream myfile("../data/canais_servidores/"+servidores[i].getNome()+"_"+(itr->second).second+".txt",fstream::app);
          stringstream ss;
          string sid;
          ss << id;
          ss >> sid;
          myfile << sid <<endl;
          myfile << mensagem <<endl;
          myfile.close();
        }
      return "Mensagem enviada";
    }
  return "Usuário não conectado";
}

string Sistema::list_messages(int id) {
  for(auto itr=usuariosLogados.begin(); itr!=usuariosLogados.end(); ++itr)
    if(itr->first == id){
      if((itr->second).second == "")
        return "Você não está em um canal";
      for(int i=0; i<servidores.size(); i++)
        if(servidores[i].getNome() == (itr->second).first)
          servidores[i].printMensagens_Server((itr->second).second, &usuarios);
      return "";
    }   
  return "Usuário não conectado";
}

/* MÉTODOS DE ARQUIVOS */
void Sistema::load_user() {
  string email,senha,nome;
  ifstream myfile ("../data/usuarios.txt");
  if (myfile.is_open()){ 
    while(getline (myfile,email)){
      getline (myfile,senha);
      getline (myfile,nome);
      Usuario temp(this->usuarios.size(), nome, senha, email);
      usuarios.push_back(temp);
    }
    myfile.close();
  }
}

void Sistema::load_server() {
  //Carregando servidores
  string id,nome,desc,code;
  ifstream myfile ("../data/servidores.txt");
  if (myfile.is_open()){ 
    while(getline (myfile,id)){
      getline (myfile,nome);
      getline (myfile,desc);
      getline (myfile,code);
      int iid;
      stringstream ss;  
      ss << id;  
      ss >> iid; 
      Servidor temp(iid, nome);

      //Carregando canais
      ifstream myfile2("../data/canais_servidores/"+temp.getNome()+".txt");
      while(getline (myfile2,nome)){
        temp.addCanal(nome);
        //Carregando mensagens do canal
        string autor,mensagem;
        ifstream myfile3("../data/canais_servidores/"+temp.getNome()+"_"+nome+".txt");
        while(getline (myfile3,autor)){
          getline (myfile3,mensagem);
          ss.clear();
          ss << autor;  
          ss >> iid;
          temp.addMensagem_Server(iid, mensagem, nome);
        }
        myfile3.close();
      }
      myfile2.close();
      servidores.push_back(temp);
    }
    myfile.close(); 
  }
}

void Sistema::copy_servers(){
  string id,nome,desc,code;
  ifstream myfile ("../data/servidores.txt");
  ofstream myfileC("../data/copia_servidores.txt");
  if (myfile.is_open()){ 
    while(getline (myfile,id)){
      myfileC << id <<endl;
      getline (myfile,nome);
      myfileC << nome <<endl;
      getline (myfile,desc);
      myfileC << desc <<endl;
      getline (myfile,code);
      myfileC << code <<endl;
    }
    myfile.close();
    myfileC.close();
  }
}