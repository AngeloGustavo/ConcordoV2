/**
 * @file usuario.h
 * @author Angelo Sales
 * @brief Classe Usuario
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;
	
class Usuario{
	private:
		int id; //<! ID do usuario
		string nome; //<! Nome do usuario
		string senha; //<! Senha do usuario	
		string email; //<! Email do usuario
		
	public:
		/**
		* @brief Construtor de Usuario
		* 
		* @param _id 
		* @param _nome 
		* @param _senha 
		* @param _email 
		*/
		Usuario(int _id,string _nome,string _senha,string _email);
			
		/**
		* @brief Retorna ID de usuario
		* 
		* @return int 
		*/
		int getId();
			
		/**
		* @brief Retorna nome do usuario
		* 
		* @return string 
		*/
		string getNome();
			
		/**
		* @brief Retorna email do usuario
		* 
		* @return string 
		*/
		string getEmail();
			
		/**
		* @brief Checa se o email e senha dados são os do usuario
		* 
		* @param _nome 
		* @param _senha 
		* @return true 
		* @return false 
		*/
		bool checkLogin(string _nome, string _senha);
};

#endif
