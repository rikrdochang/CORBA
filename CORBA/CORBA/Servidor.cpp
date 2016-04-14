#include "Servidor.h"
#include <C:\CORBA\include\omniORB4\CORBA.h>
#include <stdio.h>

void Servidor::pedirAmistad(const char* correo1, const char* correo2){
	this->conexion = getConexion();
	preAmistad(this->conexion, correo1, correo2);
}

P2P::amigos* Servidor::logueo(const char* correo, const char* pass) {
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

CORBA::Boolean Servidor::registro(const char* correo, const char* pass, const char* nombre) {
	this->conexion = getConexion();
	bool res;
	res=setUser(conexion, nombre, correo, pass);
	return res;
}

CORBA::Boolean Servidor::desregistro(const char* correo) {
	int i = 0;
	for (i = 0; i < this->conectados.length(); i++) {
		if (this->conectados[i].correo == correo) {
			this->conectados[i] = this->conectados[(this->conectados.length() - 1)];
			this->conectados[this->conectados.length() - 1].correo = "";
		}
		//Avisar
	}
	return true;
}

CORBA::Boolean Servidor::modPass(const char* correo, const char* pass1, const char* pass2) {
	this->conexion = getConexion();
	bool a;
	a = chgPass(conexion, correo, pass1, pass2);
	return a;
}

CORBA::Boolean Servidor::deslogueo(const char* correo) {
	int i = 0;
	for (i = 0; i < this->conectados.length(); i++) {
		if (this->conectados[i].correo == correo) {
			this->conectados[i] = this->conectados[this->conectados.length()];
			this->conectados[this->conectados.length()].correo = "";
			//Remover interfaz de servicio de nombres
		}
		else {
			//Avisar
		}
	}
	return true;
}

CORBA::Boolean Servidor::aceptarAmistad(const char* correo1, const char* correo2) {
	bool m, v;
	this->conexion = getConexion();
	m = amistad(conexion, correo1, correo2);
	v = amistad(conexion, correo2, correo1);

	if (m == true && v == true) {
		return true;
	}
	else {
		return false;
	}
}

P2P::buscar* Servidor::buscaAmigos(const char* nombre) {
	this->conexion = getConexion();
	P2P::buscar lista;
	lista = buscar(this->conexion, nombre);
	return &lista;
}