/**
 * @file servidor.h
 * @author Angelo Sales
 * @brief Classe Servidor
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "canaltexto.h"
#include "usuario.h"

#include <vector>
#include <string>

using namespace std;

class Servidor{		 
	private:
		int usuarioDonoId; //<! ID do dono do servidor
		string nome; //<! Nome do servidor
		string descricao; //<! Descrição do servidor
		string codigoConvite; //<! Codigo de convite do servidor
		vector<int> participantesIDs; //<! IDs de participantes do servidor
		vector<CanalTexto> canaisTexto; //<! Canais de texto do servidor

	public:	
		/**	
		* @brief Construtor de Servidor
		* 
		* @param _id 
		* @param _nome 
		*/
		Servidor(int _id, string _nome);
	
		/**
		* @brief Retorna o ID do dono do servidor
		* 
		* @return int 
		*/
		int getDonoId();
	
		/**
		* @brief Retorna o nome do servidor
		* 
		* @return string 
		*/
		string getNome();
	
		/**
		* @brief Altera a descrição do servidor
		* 
		* @param _descricao 
		*/
		void setDescricao(string _descricao);
					
		/**
		* @brief Retorna a descrição do servidor
		* 
		* @return string 
		*/
		string getDescricao();
	
		/**
		* @brief Altera o codigo de convite do servidor
		* 
		* @param _codigo 
		*/
		void setCodigo(string _codigo);
					
		/**
		* @brief Retorna o codigo de convite do servidor
		* 
		* @return string 
		*/
		string getCodigo();
	
		/**
		* @brief Adiciona o ID do usuario ao vetor de participantes do servidor
		* 
		* @param _id 
		*/
		void addParticipante(int _id);
		bool checkParticipante(int _id);
			
		/**
		* @brief Remove ID do usuario do vetor de participantes do servidor
		* 
		* @param _id 
		*/
		void delParticipante(int _id);
			
		/**
		* @brief Lista canais do servidor
		* 
		*/
		void printCanais();
			
		/**
		* @brief Adiciona canal ao servidor
		* 
		* @param nome 
		*/
		void addCanal(string nome);
			
		/**
		* @brief Checa se já existe canal no servidor com o nome dado
		* 
		* @param nome 
		* @return true 
		* @return false 
		*/
		bool checkCanal(string nome);
	
		/**
		* @brief Adiciona elemento ao vetor de mensagens
		* 
		* @param id 
		* @param mensagem 
		* @param canal 
		*/
		void addMensagem_Server(int id, const string mensagem, string canal);
			
		/**
		* @brief Lista elementos do vetor de mensagens
		* 
		* @param canal 
		* @param usuarios 
		*/
		void printMensagens_Server(string canal, vector<Usuario> *usuarios);
};

#endif
