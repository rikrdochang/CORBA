#include "Servidor.h"
#include <C:\CORBA\include\omniORB4\CORBA.h>

void Servidor::pedirAmistad(const char* correo1, const char* correo2){
	this->conexion = getConexion();
	preAmistad(this->conexion, correo1, correo2);
}

P2P::amigos* Servidor::logueo(const char* correo, const char* pass) {
	this->conexion = getConexion();
	bool user;
	user = getUser(this->conexion, correo, pass);
	P2P::amigos *lista = new P2P::amigos();
	CORBA::ULong tam = (*lista).length();
	P2P::amigo aux;
	
	if (user == true) {
		(*lista) = getAmigos(this->conexion, correo, this->conectados);
	}
	else {
		(*lista).length(tam + 1);
		aux.correo = "fallo@fallo.com";
		aux.estado = false;
		(*lista)[tam] = aux;
	}

	int i;
	for (i = 0; i < (*lista).length()-1; i++) {
		if ((*lista)[i].estado == true) {
			string atontado = (string)(*lista)[i].correo;
			CosNaming::Name name;
			name.length(1);
			string correoaux = "sc";
			correoaux= atontado+ correoaux;
			name[0].id = CORBA::string_dup(correoaux.c_str());
			name[0].kind = CORBA::string_dup("");
			CORBA::Object_ptr aux;
			aux = (*this->nc)->resolve(name);
			P2P::sc_var cliente = P2P::sc::_narrow(aux);
			cliente->notificar(correo, true);
		}
	}

	tam = (this->conectados).length();
	this->conectados.length(tam + 1);
	aux.correo = correo;
	aux.estado = true;
	this->conectados[tam] = aux;
	return lista;
}

CORBA::Boolean Servidor::registro(const char* correo, const char* pass, const char* nombre) {
	this->conexion = getConexion();
	bool res;
	res=setUser(conexion, nombre, correo, pass);
	return res;
}

CORBA::Boolean Servidor::desregistro(const char* correo) {
	if (deslogueo(correo)) {
		if (delUser(this->conexion, correo)) {
			return true;
		}
	}
	return false;
}

CORBA::Boolean Servidor::modPass(const char* correo, const char* pass1, const char* pass2) {
	this->conexion = getConexion();
	bool a;
	a = chgPass(conexion, correo, pass1, pass2);
	return a;
}

CORBA::Boolean Servidor::deslogueo(const char* correo) {
	int i, j;
	for (i = 0; i < this->conectados.length(); i++) {
		if (this->conectados[i].correo == correo) {
			this->conectados[i] = this->conectados[this->conectados.length()];
			this->conectados.length((this->conectados.length() - 1));
			this->conexion = getConexion();
			P2P::amigos lista = getAmigos(this->conexion,correo,this->conectados);
			for (j = 0; j < lista.length(); j++) {
				if (lista[j].estado) {
					CosNaming::Name name;
					name.length(1);
					string atontado = lista[j].correo;
					string correoaux = "sc";
					correoaux = atontado + correoaux;
					name[0].id = CORBA::string_dup(correoaux.c_str());
					name[0].kind = CORBA::string_dup("");
					CORBA::Object_ptr aux;
					aux = (*this->nc)->resolve(name);
					P2P::sc_var cliente = P2P::sc::_narrow(aux);
					cliente->notificar(correo, false);
				}
			}
		}
	}
	CosNaming::Name name;
	name.length(1);
	string correoaux = "sc";
	correoaux = correo + correoaux;
	name[0].id = CORBA::string_dup(correoaux.c_str());
	name[0].kind = CORBA::string_dup("");
	CORBA::Object_ptr aux;
	(*this->nc)->unbind(name);
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