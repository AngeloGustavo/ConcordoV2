/**
 * @file canaltexto.h
 * @author Angelo Sales
 * @brief Classe CanalTexto
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "mensagem.h"
#include "usuario.h"

#include <vector>

using namespace std;

class CanalTexto{
	private:
		string nome; //<! Nome do canal de texto
		vector<Mensagem> mensagens; //<! Vetor de mensagens
		
	public:
		/**
		* @brief Construtor de CanalTexto
		* 
		* @param _nome 
		*/
		CanalTexto(string _nome);
			
		/**
		* @brief Retorna nome do canal
		* 
		* @return string 
		*/
		string getNome();
	
		/**
		* @brief Adiciona elemento ao vetor de mensagens
		* 
		* @param id 
		* @param mensagem 
		*/
		void addMensagem(int id, const string mensagem);
			
		/**
		* @brief Lista nome dos elementos do vetor de mensagens
		* 
		* @param usuarios 
		*/
		void printMensagens(vector<Usuario> *usuarios);
	
		/**
		* @brief Retorna string de Data e Hora no padrão especificado no documento do projeto
		* 
		* @return string 
		*/
		string HoraData();
};

#endif
