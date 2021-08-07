/**
 * @file mensagem.h
 * @author Angelo Sales
 * @brief Classe Mensagem
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

using namespace std;

class Mensagem{
    private:
        string dataHora; //<! String de Data e Hora no padrão especificado no documento do projeto
        int enviadaPor; //<! ID do autor da mensagem
        string conteudo; //<! Conteudo da mensagem
    public:
        /**
        * @brief Construtor de Mensagem
        * 
        * @param _dataHora 
        * @param _enviadaPor 
        * @param _conteudo 
        */
        Mensagem(string _dataHora, int _enviadaPor, string _conteudo);
        	
        /**
        * @brief Retorna string de Data e Hora
        * 
        * @return string 
        */
        string getDataHora();
        	
        /**
        * @brief Retorna ID do autor da mensagem
        * 
        * @return int 
        */
        int getEnviadaPor();	

        /**
        * @brief Retorna conteudo da mensagem
        * 
        * @return string 
        */
        string getConteudo();       
};

#endif