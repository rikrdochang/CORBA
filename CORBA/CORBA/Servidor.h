#pragma once
#include "AccessDB.h"
#include "DataContainer.h"

using namespace std;

class Servidor : public POA_P2P::cs {
public:
	sql::Connection *conexion;
	P2P::amigos conectados;
	virtual void pedirAmistad(string correo1, string correo2);
	virtual P2P::amigos* logueo(string correo, string pass, P2P::sc interfaz);
	virtual bool registro(string correo, string pass, string nombre);
	virtual bool desregistro(string correo);
	virtual bool modPass(string correo, string pass1, string pass2);
	virtual bool deslogueo(string correo);
	virtual bool aceptarAmistad(string correo1, string correo2);
	virtual P2P::buscar* buscaAmigos(string nombre);
};