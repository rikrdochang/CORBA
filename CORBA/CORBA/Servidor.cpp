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
		this->conectados[tam].correo = correo.c_str();
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
	bool res;
	res=setUser(conexion, nombre, correo, pass);
	return res;
}

bool Servidor::desregistro(string correo) {
	int i = 0;
	for (i = 0; i < this->conectados.length(); i++) {
		if (this->conectados[i].correo == correo.c_str()) {
			this->conectados[i] = this->conectados[(this->conectados.length() - 1)];
			this->conectados[this->conectados.length() - 1] = NULL;
		}
		//Avisar
	}
}

bool Servidor::modPass(string correo, string pass1, string pass2) {
	this->conexion = getConexion();
	bool a;
	a = chgPass(conexion, correo, pass1, pass2);
	return a;
}

bool Servidor::deslogueo(string correo) {
	int i = 0;
	for (i = 0; i < this->conectados.length(); i++) {
		if (this->conectados[i].correo == correo.c_str()) {
			this->conectados[i] = this->conectados[this->conectados.length()];
			this->conectados[this->conectados.length()] = NULL;
			//Remover interfaz de servicio de nombres
		}
		else {
			//Avisar
		}
	}
}

bool Servidor::aceptarAmistad(string correo1, string correo2) {
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

P2P::buscar* Servidor::buscaAmigos(string nombre) {
	this->conexion = getConexion();
	P2P::buscar lista;
	lista = buscar(nombre);
	return &lista;
}