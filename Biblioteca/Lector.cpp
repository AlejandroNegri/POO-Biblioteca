#include <algorithm>
#include "Lector.h"

Lector::Lector(string p_nombre, string p_apellido, string p_dni, string p_domicilio, string p_tel, int p_numeroLector):
	Nombre(p_nombre), Apellido(p_apellido), DNI(p_dni), Domicilio(p_domicilio), Tel(p_tel), NumeroLector(p_numeroLector){};
string Lector::VerNombre()const{ return Nombre; };	
string Lector::VerApellido()const { return Apellido; };	
string Lector::VerDNI() const { return DNI; };	
string Lector::VerDomicilio() const { return Domicilio; };	
string Lector::VerTel() const { return Tel; };	
int Lector::VerNumeroLector() const { return NumeroLector; }; 
