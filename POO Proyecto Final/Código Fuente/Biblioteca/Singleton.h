/**
* @file Singleton.h
* @brief Declaraciones de todo lo necesario para trabajar con la clase Singleton
*
* Este archivo define la clase Singleton, utilizada para trabajar con una única
* instancia de la clase Biblioteca
**/

#ifndef SINGLETON_H
#define SINGLETON_H
#include "Biblioteca.h"

/**
* @brief Clase Singleton que representa a una Biblioteca. 
*
* Permite trabajar con una única biblioteca para no crear múltiples instancias
**/
class Singleton:public Biblioteca {
	static Singleton *instancia; // puntero a la única instancia
	Singleton():Biblioteca(){}; // constructor privado
public:
	/// @brief Método para obtener la instancia, única forma de hacerlo
	static Singleton *ObtenerInstancia() {
		// si no hay instancia, la crea
		if (!instancia) instancia=new Singleton();
		return instancia;
	}
};
#endif


	
