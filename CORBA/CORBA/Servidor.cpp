#include "Servidor.h"
#include <C:\CORBA\include\omniORB4\CORBA.h>
#include <stdio.h>

void Servidor::pedirAmistad(string correo1, string correo2){
	this->conexion = getConexion();
	preAmistad(this->conexion, correo1, correo2);
}

P2P::amigos* Servidor::logueo(string correo, string pass, P2P::sc interfaz) {
	this->conexion = getConexion();
	bool user;
	user = getUser(this->conexion, correo, pass);
	P2P::amigos lista;
	if (user = true) {
		
	}
	else {
		P2P::amigo aux;
		aux.correo = "fallo@fallo.com";
		aux.estado = false;
		lista[0] = aux;
	}
	return &lista;
}
