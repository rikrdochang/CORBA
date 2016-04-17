#pragma once
#include "AccessDB.h"
#include "DataContainer.h"

using namespace std;

class Servidor : public POA_P2P::cs {
public:
	CORBA::ORB_var *orb;
	CosNaming::NamingContext_ptr *nc;
	sql::Connection *conexion;
	P2P::amigos conectados;
	std::mutex mtx;
	virtual ::CORBA::Boolean pedirAmistad(const char* correo1, const char* correo2);
	virtual P2P::amigos* logueo(const char* correo, const char* pass);
	virtual ::CORBA::Boolean registro(const char* correo, const char* pass, const char* nombre);
	virtual ::CORBA::Boolean desregistro(const char* correo);
	virtual ::CORBA::Boolean modPass(const char* correo, const char* pass1, const char* pass2);
	virtual ::CORBA::Boolean deslogueo(const char* correo);
	virtual ::CORBA::Boolean aceptarAmistad(const char* correo1, const char* correo2);
	virtual P2P::buscar* buscaAmigos(const char* nombre, const char* correo1);
	virtual ::CORBA::Boolean noAmistad(const char* correo1, const char* correo2);
	virtual void initAmistad(const char* correo1);
};