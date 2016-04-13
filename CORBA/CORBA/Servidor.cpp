#include "Servidor.h"
#include <C:\CORBA\include\omniORB4\CORBA.h>
#include <stdio.h>

void Servidor::pedirAmistad(string correo){
	this->conexion = getConexion();
	preAmistad(this->conexion, , correo);
}