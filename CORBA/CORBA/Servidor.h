#pragma once
#include "interface.hh"
#include "AccessDB.h"
#include "DataContainer.h"

using namespace std;

class Servidor : public POA_P2P::cs {
public:
	sql::Connection *conexion;
	virtual void pedirAmistad(string correo1, string correo2);
	virtual P2P::amigos* logueo(string correo, string pass, P2P::sc interfaz);
	bool registro(string correo, string pass, string nombre);
	bool desregistro(string correo);
	bool modPass(string correo, string pass1, string pass2);
	bool deslogueo(string correo, P2P::sc interfaz);
	bool aceptarAmistad(string correo);
};