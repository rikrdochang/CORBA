#include "AccessDB.h"

sql::Connection* getConexion() {
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *connection;

	driver = sql::mysql::get_mysql_driver_instance();
	connection = driver->connect("tcp://localhost:3306/PDB", "lueiro", "0612");

	return connection;
}

void setUser(sql::Connection* conexion, std::string nombre, std::string correo, std::string pass) {
	sql::Statement *statement;
	statement = conexion->createStatement();

	std::string aux;
	aux = "INSERT INTO usuarios VALUES('" + correo + "','" + nombre + "','" + pass + "');";
	try {
		statement->executeQuery(aux);
	}catch (sql::SQLException &e) {}
}

int getUser(sql::Connection* conexion, std::string nombre) {
	sql::Statement *statement;
	sql::ResultSet *resultset;

	statement = conexion->createStatement();

	std::string aux;
	aux = "SELECT * FROM usuarios WHERE nombre='" + nombre + "';";
	resultset = statement->executeQuery(aux);

	while (resultset->next()) {
		return 1;
	}
	return 0;
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

std::string* getAmigos(sql::Connection* conexion, std::string correo) {
	sql::Statement *statement;
	sql::ResultSet *resultset;

	statement = conexion->createStatement();

	std::string aux;
	int size=1;
	aux = "SELECT COUNT(correo2) FROM amigos WHERE correo1='" + correo + "';";
	resultset = statement->executeQuery(aux);

	if (resultset->next()) {
		size=resultset->getInt(1);
	}else {
		std::string amigo[1];
		amigo[0] = "Null";
		return amigo;
	}

	std::string *amigos = new std::string[3];
	aux = "SELECT correo2 FROM amigos WHERE correo1='" + correo + "';";
	resultset = statement->executeQuery(aux);

	int i = 0;
	for (i = 0; resultset->next(); i++) {
		std::string correo2 = resultset->getString(1);
		amigos[i] = correo2;
	}
	return amigos;
}