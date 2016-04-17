#include "Servidor.h"
#include <C:\CORBA\include\omniORB4\CORBA.h>

CORBA::Boolean Servidor::pedirAmistad(const char* correo1, const char* correo2){
	if (strcmp(correo1, correo2) == 0) {
		return false;
	}
	this->conexion = getConexion();
	this->mtx.lock();
	bool a=preAmistad(this->conexion, correo1, correo2);
	if (a) {
		int i = 0;
		for (i = 0; i < this->conectados.length(); i++) {
			if (strcmp(this->conectados[i].correo, correo2) == 0) {
				CosNaming::Name name;
				name.length(1);
				string correoaux = "sc";
				correoaux = correo2 + correoaux;
				name[0].id = CORBA::string_dup(correoaux.c_str());
				name[0].kind = CORBA::string_dup("");
				CORBA::Object_ptr aux;
				aux = (*this->nc)->resolve(name);
				P2P::sc_var cliente = P2P::sc::_narrow(aux);
				cliente->sendAmistad(correo1);
			}
		}
		this->mtx.unlock();
		return true;
	}
	else {
		this->mtx.unlock();
		return false;
	}
}

P2P::amigos* Servidor::logueo(const char* correo, const char* pass) {
	int i;
	P2P::amigos *lista = new P2P::amigos();
	P2P::amigo aux;
	this->conexion = getConexion();
	bool user;
	this->mtx.lock();
	user = getUser(this->conexion, correo, pass);
	CORBA::ULong tam = (*lista).length();
	if (user == true) {
		for (i = 0; i < this->conectados.length(); i++) {
			if (strcmp(this->conectados[i].correo, correo) == 0) {
				(*lista).length((*lista).length() + 1);
				aux.correo = "relogueo@relogueo.com";
				aux.estado = false;
				(*lista)[0] = aux;
				this->mtx.unlock();
				return lista;
			}
		}
		(*lista) = getAmigos(this->conexion, correo, this->conectados);
	}
	else {
		(*lista).length(tam + 1);
		aux.correo = "fallo@fallo.com";
		aux.estado = false;
		(*lista)[tam] = aux;
		this->mtx.unlock();
		return lista;
	}
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
	this->mtx.unlock();
	return lista;
}

CORBA::Boolean Servidor::registro(const char* correo, const char* pass, const char* nombre) {
	this->conexion = getConexion();
	bool res;
	P2P::amigo aux;
	this->mtx.lock();
	res=setUser(conexion, nombre, correo, pass);
	CORBA::ULong tam = (this->conectados).length();
	this->conectados.length(tam + 1);
	aux.correo = correo;
	aux.estado = true;
	this->conectados[tam] = aux;
	this->mtx.unlock();
	return res;
}

CORBA::Boolean Servidor::desregistro(const char* correo) {
	this->mtx.lock();
	if (deslogueo(correo)) {
		if (delUser(this->conexion, correo)) {
			this->mtx.unlock();
			return true;
		}
	}
	this->mtx.unlock();
	return false;
}

CORBA::Boolean Servidor::modPass(const char* correo, const char* pass1, const char* pass2) {
	this->conexion = getConexion();
	this->mtx.lock();
	bool a = chgPass(conexion, correo, pass1, pass2);
	this->mtx.unlock();
	return a;
}

CORBA::Boolean Servidor::deslogueo(const char* correo) {
	int i, j;
	this->mtx.lock();
	for (i = 0; i < this->conectados.length(); i++) {
		if (strcmp(this->conectados[i].correo,correo)==0) {
			this->conectados[i] = this->conectados[this->conectados.length()-1];
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
	(*this->nc)->unbind(name);
	correoaux = "cc";
	correoaux = correo + correoaux;
	name[0].id = CORBA::string_dup(correoaux.c_str());
	(*this->nc)->unbind(name);
	this->mtx.unlock();
	return true;
}

CORBA::Boolean Servidor::aceptarAmistad(const char* correo1, const char* correo2) {
	this->conexion = getConexion();
	this->mtx.lock();
	bool m = amistad(conexion, correo1, correo2);
	if (m) {
		CosNaming::Name name;
		name.length(1);
		string correoaux = "sc";
		correoaux = correo1 + correoaux;
		name[0].id = CORBA::string_dup(correoaux.c_str());
		name[0].kind = CORBA::string_dup("");
		CORBA::Object_ptr aux;
		aux = (*this->nc)->resolve(name);
		P2P::sc_var cliente = P2P::sc::_narrow(aux);
		int i;
		bool estado = false;
		for (i = 0; i < this->conectados.length(); i++) {
			if (strcmp(this->conectados[i].correo, correo2) == 0) {
				estado = true;
			}
		}
		cliente->notificar(correo2, estado);
		correoaux = "sc";
		correoaux = correo2 + correoaux;
		name[0].id = CORBA::string_dup(correoaux.c_str());
		aux = (*this->nc)->resolve(name);
		cliente = P2P::sc::_narrow(aux);
		estado = false;
		for (i = 0; i < this->conectados.length(); i++) {
			if (strcmp(this->conectados[i].correo, correo1) == 0) {
				estado = true;
			}
		}
		cliente->notificar(correo1, estado);
	}
	this->mtx.unlock();
	return m;
}

P2P::buscar* Servidor::buscaAmigos(const char* nombre, const char* correo1) {
	this->conexion = getConexion();
	P2P::buscar *lista = new P2P::buscar;
	this->mtx.lock();
	(*lista) = buscar(this->conexion, nombre, correo1);
	this->mtx.unlock();
	return lista;
}

CORBA::Boolean Servidor::noAmistad(const char* correo1, const char* correo2) {
	this->conexion = getConexion();
	this->mtx.lock();
	bool a = rechazarAmig(this->conexion,correo1,correo2);
	this->mtx.unlock();
	return a;
}

void Servidor::initAmistad(const char* correo1) {
	this->conexion = getConexion();
	CosNaming::Name name;
	name.length(1);
	string correoaux = "sc";
	correoaux = correo1 + correoaux;
	name[0].id = CORBA::string_dup(correoaux.c_str());
	name[0].kind = CORBA::string_dup("");
	CORBA::Object_ptr aux;
	aux = (*this->nc)->resolve(name);
	P2P::sc_var cliente = P2P::sc::_narrow(aux);
	this->mtx.lock();
	avisoAmistad(this->conexion, correo1, cliente);
	this->mtx.unlock();
}