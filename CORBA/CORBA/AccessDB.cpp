#include "AccessDB.h"

using namespace std;

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
	aux = "SELECT * FROM usuarios WHERE correo='" + nombre + "' AND pass='" + pass + "';";
	resultset = statement->executeQuery(aux);

	if (resultset->next()) {
		return true;
	}
	else {
		return false;
	}
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

	aux = "DELETE FROM amigos WHERE correo1='" + correo + "';";
	try {
		statement->executeQuery(aux);
	}
	catch (sql::SQLException &e) {}

	aux = "DELETE FROM amigos WHERE correo2='" + correo + "';";
	try {
		statement->executeQuery(aux);
	}
	catch (sql::SQLException &e) {}

	aux = "DELETE FROM pendientes WHERE correo1='" + correo + "';";
	try {
		statement->executeQuery(aux);
	}
	catch (sql::SQLException &e) {}

	aux = "DELETE FROM pendientes WHERE correo2='" + correo + "';";
	try {
		statement->executeQuery(aux);
	}
	catch (sql::SQLException &e) {}

	aux = "SELECT * FROM usuarios WHERE correo='" + correo + "';";
	resultset = statement->executeQuery(aux);

	while (resultset->next()) {
		return false;
	}
	return true;
}

bool chgPass(sql::Connection* conexion, std::string correo, std::string pass1, std::string pass2) {
	sql::Statement *statement;
	statement = conexion->createStatement();

	std::string aux;
	aux = "UPDATE usuarios SET pass='" + pass2 + "' WHERE correo='" + correo + "' AND pass='" + pass1 + "';";
	try {
		statement->executeQuery(aux);
	}
	catch (sql::SQLException &e) {}

	sql::ResultSet *resultset;
	aux = "SELECT * FROM usuarios WHERE correo='" + correo + "' AND pass='" + pass2 + "';";
	resultset = statement->executeQuery(aux);

	if (resultset->next()) {
		return true;
	}
	else {
		return false;
	}
}

P2P::amigos getAmigos(sql::Connection* conexion, std::string correo, P2P::amigos lista) {
	sql::Statement *statement;
	sql::ResultSet *resultset;
	statement = conexion->createStatement();

	std::string aux;
	aux = "SELECT correo2 FROM amigos WHERE correo1='" + correo + "';";
	resultset = statement->executeQuery(aux);

	P2P::amigos *todos = new P2P::amigos();
	CORBA::ULong tam = (*todos).length();
	P2P::amigo tmp;
	int i = 0, j = 0;
	for (i = 0; resultset->next(); i++) {
		(*todos).length(tam + 1);
		tmp.correo = resultset->getString(1).c_str();
		tmp.estado = false;
		for (j = 0; j < lista.length(); j++){
			if ((std::string)tmp.correo==(std::string)lista[j].correo) {
				tmp.estado = true;
			}
		}
		(*todos)[tam] = tmp;
		tam = (*todos).length();
	}
	(*todos).length(tam + 1);
	tmp.correo = "ready@ready.com";
	tmp.estado = false;
	(*todos)[tam] = tmp;
	return (*todos);
}

void preAmistad(sql::Connection* conexion, std::string correo1, std::string correo2) {
	sql::Statement *statement;
	statement = conexion->createStatement();

	std::string aux;
	aux = "INSERT INTO pendiente VALUES('" + correo2 + "','" + correo1 + "');";
	try {
		statement->executeQuery(aux);
	}
	catch (sql::SQLException &e) {}

	delete statement;
}

bool amistad(sql::Connection* conexion, std::string correo1, std::string correo2) {
	sql::Statement *statement;
	sql::ResultSet *resultset;
	statement = conexion->createStatement();

	std::string aux;
	aux = "SELECT * FROM pendiente WHERE correo1='" + correo1 + "' AND correo2='" + correo2 + "';";
	resultset = statement->executeQuery(aux);

	if (resultset->next()) {
		aux = "INSERT INTO amigos VALUES('" + correo1 + "','" + correo2 + "');";
		try {
			statement->executeQuery(aux);
		}
		catch (sql::SQLException &e) {}

		aux = "SELECT * FROM amigos WHERE correo1='" + correo1 + "' AND correo2='" + correo2 + "';";
		resultset = statement->executeQuery(aux);
		if (resultset->next()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

P2P::buscar buscar(sql::Connection* conexion, std::string nombre) {
	sql::Statement *statement;
	sql::ResultSet *resultset;
	statement = conexion->createStatement();

	std::string aux;
	aux = "SELECT correo FROM usuarios WHERE nombre='" + nombre + "';";
	resultset = statement->executeQuery(aux);

	P2P::buscar lista;
	int i;
	for (i = 0; resultset->next(); i++) {
		lista[i] = resultset->getString(1).c_str();
	}
	return lista;
}

void solPendientes() {

}