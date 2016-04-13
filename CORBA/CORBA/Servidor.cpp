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
		lista = getAmigos(this->conexion, correo, this->conectados);
		int tam = this->conectados.length();
		this->conectados[tam].correo = correo;
		this->conectados[tam].estado = true;
	}
	else {
		P2P::amigo aux;
		aux.correo = "fallo@fallo.com";
		aux.estado = false;
		lista[0] = aux;
	}
	return &lista;
}

bool Servidor::registro(string correo, string pass, string nombre) {
	this->conexion = getConexion();
	int res;
	res=setUser(conexion, nombre, correo, pass);
	if (res == 1) {
		return true;
	}
	else {
		return false;
	}
}