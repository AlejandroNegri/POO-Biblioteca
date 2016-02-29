/**
* @file Singleton.h
* @brief Declaraciones de todo lo necesario para trabajar con la clase Singleton
*
* Este archivo define la clase Singleton, utilizada para trabajar con una �nica
* instancia de la clase Biblioteca
**/

#ifndef SINGLETON_H
#define SINGLETON_H
#include "Biblioteca.h"

/**
* @brief Clase Singleton que representa a una Biblioteca. 
*
* Permite trabajar con una �nica biblioteca para no crear m�ltiples instancias
**/
class Singleton:public Biblioteca {
	static Singleton *instancia; // puntero a la �nica instancia
	Singleton():Biblioteca(){}; // constructor privado
public:
	/// @brief M�todo para obtener la instancia, �nica forma de hacerlo
	static Singleton *ObtenerInstancia() {
		// si no hay instancia, la crea
		if (!instancia) instancia=new Singleton();
		return instancia;
	}
};
#endif


	
