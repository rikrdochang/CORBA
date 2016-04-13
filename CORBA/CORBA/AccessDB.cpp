#include "AccessDB.h"
#include "interface.hh"

sql::Connection* getConexion() {
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *connection;

	driver = sql::mysql::get_mysql_driver_instance();
	connection = driver->connect("tcp://localhost:3306/PDB", "lueiro", "0612");

	return connection;
}

bool setUser(sql::Connection* conexion, std::string nombre, std::string correo, std::string pass) {
	sql::Statement *statement;
	sql::ResultSet *resultset;
	statement = conexion->createStatement();

	std::string aux;
	aux = "SELECT * FROM usuarios WHERE correo='" + correo + "';";
	resultset = statement->executeQuery(aux);
	if (resultset->next()) {
		return false;
	}
	else {
		aux = "INSERT INTO usuarios VALUES('" + correo + "','" + nombre + "','" + pass + "');";
		try {
			statement->executeQuery(aux);
		}
		catch (sql::SQLException &e) {}
		return true;
	}
}

bool getUser(sql::Connection* conexion, std::string nombre, std::string pass) {
	sql::Statement *statement;
	sql::ResultSet *resultset;

	statement = conexion->createStatement();

	std::string aux;
	aux = "SELECT * FROM usuarios WHERE nombre='" + nombre + "' AND pass='" + pass + "';";
	resultset = statement->executeQuery(aux);

	while (resultset->next()) {
		return true;
	}
	return false;
}

bool delUser(sql::Connection* conexion, std::string correo) {
	sql::Statement *statement;
	sql::ResultSet *resultset;
	statement = conexion->createStatement();

	std::string aux;
	aux = "DELETE FROM usuarios WHERE correo='"+correo+"';";
	try {
		statement->executeQuery(aux);
	}
	catch (sql::SQLException &e) {}

	aux = "SELECT * FROM usuarios WHERE correo'" + correo + "';";
	resultset = statement->executeQuery(aux);

	while (resultset->next()) {
		return false;
	}
	return true;
}

void modPass(sql::Connection* conexion, std::string nombre, std::string pass) {
	sql::Statement *statement;
	statement = conexion->createStatement();

	std::string aux;
	aux = "UPDATE usuarios SET pass='" + pass + "' WHERE nombre='" + nombre + "';";
	try {
		statement->executeQuery(aux);
	}
	catch (sql::SQLException &e) {}
}

P2P::amigos getAmigos(sql::Connection* conexion, std::string correo, P2P::amigos lista) {
	sql::Statement *statement;
	sql::ResultSet *resultset;

	statement = conexion->createStatement();

	std::string aux;
	aux = "SELECT correo2 FROM amigos WHERE correo1='" + correo + "';";
	resultset = statement->executeQuery(aux);

	P2P::amigos amigos;
	int i = 0, j = 0;
	for (i = 0; resultset->next(); i++) {
		amigos[i].correo = resultset->getString(1).c_str();
		for (j = 0; j < lista.length(); j++) {
			if (amigos[i].correo == lista[j].correo) {
				amigos[i].estado = true;
				j = lista.length();
			}
		}
	}
	amigos[i + 1].correo = "ready@ready.com";
	return amigos;
}

void preAmistad(sql::Connection* conexion, std::string correo1, std::string correo2) {
	sql::Statement *statement;
	statement = conexion->createStatement();

	std::string aux;
	aux = "INSERT INTO pendiente VALUES('" + correo1 + "','" + correo2 + "');";
	try {
		statement->executeQuery(aux);
	}
	catch (sql::SQLException &e) {}

	aux = "INSERT INTO pendiente VALUES('" + correo2 + "','" + correo1 + "');";
	try {
		statement->executeQuery(aux);
	}
	catch (sql::SQLException &e) {}

	delete statement;
}