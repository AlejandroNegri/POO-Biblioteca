/**
* @file Lector.cpp
* @brief Implementaciones de todo lo necesario para trabajar con la clase Lector
**/
#include <algorithm>
#include "Lector.h"

Lector::Lector(string p_nombre, string p_apellido, string p_dni, string p_domicilio, string p_tel, int p_numeroLector):
	Nombre(p_nombre), Apellido(p_apellido), DNI(p_dni), Domicilio(p_domicilio), Tel(p_tel), NumeroLector(p_numeroLector), Oculto(false){};
	
Lector::Lector(string p_nombre, string p_apellido, string p_dni, string p_domicilio, string p_tel, int p_numeroLector, bool p_oculto):
	Nombre(p_nombre), Apellido(p_apellido), DNI(p_dni), Domicilio(p_domicilio), Tel(p_tel), NumeroLector(p_numeroLector), Oculto(p_oculto){};
	
string Lector::VerNombre()const				{ return Nombre; };	
string Lector::VerApellido()const 			{ return Apellido; };	
string Lector::VerApellidoYNombre()const	{ return Apellido + ", " + Nombre; };
string Lector::VerDNI() const 				{ return DNI; };	
string Lector::VerDomicilio() const 		{ return Domicilio; };	
string Lector::VerTel() const 				{ return Tel; };	
int Lector::VerNumeroLector() const			{ return NumeroLector; }; 
bool Lector::EstaOculto() const 			{ return Oculto; }
void Lector::Ocultar() 						{ Oculto = true; }
