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
	sql::Statement *statement = NULL;
	sql::ResultSet *resultset = NULL;

	conexion->setAutoCommit(0);
	try {
		statement = conexion->createStatement();
		std::string aux;
		aux = "SELECT * FROM usuarios WHERE correo='" + correo + "';";
		resultset = statement->executeQuery(aux);
		if (resultset->next()) {
			conexion->commit();
			conexion->setAutoCommit(1);
			delete statement;
			delete resultset;
			return false;
		}
		else {
			aux = "INSERT INTO usuarios VALUES('" + correo + "','" + nombre + "','" + pass + "');";
			statement->executeUpdate(aux);
			conexion->commit();
			conexion->setAutoCommit(1);
			delete statement;
			delete resultset;
			return true;
		}
	}
	catch (sql::SQLException &e) {
		conexion->rollback();
		conexion->setAutoCommit(1);
		delete statement;
		delete resultset;
		return false;
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
	sql::Statement *statement = NULL;
	sql::ResultSet *resultset = NULL;

	conexion->setAutoCommit(0);
	try {
		statement = conexion->createStatement();
		std::string aux;
		aux = "DELETE FROM amigos WHERE correo1='" + correo + "';";
		statement->executeUpdate(aux);
		aux = "DELETE FROM amigos WHERE correo2='" + correo + "';";
		statement->executeUpdate(aux);
		aux = "DELETE FROM pendiente WHERE correo1='" + correo + "';";
		statement->executeUpdate(aux);
		aux = "DELETE FROM pendiente WHERE correo2='" + correo + "';";
		statement->executeUpdate(aux);
		aux = "DELETE FROM usuarios WHERE correo='" + correo + "';";
		statement->executeUpdate(aux);
		conexion->commit();
		conexion->setAutoCommit(1);
		delete statement;
		delete resultset;
		return true;
	}
	catch(sql::SQLException &e){
		conexion->rollback();
		conexion->setAutoCommit(1);
		delete statement;
		delete resultset;
		return false;
	}
}

bool chgPass(sql::Connection* conexion, std::string correo, std::string pass1, std::string pass2) {
	sql::Statement *statement = NULL;
	sql::ResultSet *resultset = NULL;

	conexion->setAutoCommit(0);
	try {
		statement = conexion->createStatement();
		std::string aux = "SELECT pass FROM usuarios WHERE correo='" + correo + "';";
		resultset = statement->executeQuery(aux);
		resultset->next();
		if (strcmp(resultset->getString(1).c_str(), pass1.c_str()) == 0) {
			statement->executeUpdate(aux);
			conexion->commit();
			conexion->setAutoCommit(1);
			delete statement;
			delete resultset;
			return true;
		}
		else {
			conexion->setAutoCommit(1);
			delete statement;
			delete resultset;
			return false;
		}
	}
	catch (sql::SQLException &e) {
		conexion->rollback();
		conexion->setAutoCommit(1);
		delete statement;
		delete resultset;
		return false;
	}
}

P2P::amigos getAmigos(sql::Connection* conexion, std::string correo, P2P::amigos lista) {
	sql::Statement *statement = NULL;
	sql::ResultSet *resultset = NULL;

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

	delete statement;
	delete resultset;
	return (*todos);
}

bool preAmistad(sql::Connection* conexion, std::string correo1, std::string correo2) {
	sql::Statement *statement = NULL;
	sql::ResultSet *resultset = NULL;
	
	conexion->setAutoCommit(0);
	try {
		statement = conexion->createStatement();
		std::string aux = "SELECT * FROM usuarios WHERE correo='" + correo2 + "';";
		resultset = statement->executeQuery(aux);
		if (resultset->next()) {
			aux = "SELECT * FROM pendiente WHERE correo1='" + correo1 + "' AND correo2='" + correo2 + "';";
			resultset = statement->executeQuery(aux);
			if (resultset->next()) {
				delete statement;
				delete resultset;
				conexion->setAutoCommit(1);
				return false;
			}
			aux = "SELECT * FROM amigos WHERE correo1='" + correo1 + "' AND correo2='" + correo2 + "';";
			resultset = statement->executeQuery(aux);
			if (resultset->next()) {
				delete statement;
				delete resultset;
				conexion->setAutoCommit(1);
				return false;
			}

			aux = "INSERT INTO pendiente VALUES('" + correo1 + "','" + correo2 + "');";
			statement->executeUpdate(aux);
			conexion->commit();
			conexion->setAutoCommit(1);
			delete statement;
			delete resultset;
			return true;
		}
		conexion->setAutoCommit(1);
		delete statement;
		delete resultset;
		return false;
	}
	catch (sql::SQLException &e) {
		conexion->rollback();
		conexion->setAutoCommit(1);
		delete statement;
		delete resultset;
		return false;
	}
}

bool amistad(sql::Connection* conexion, std::string correo1, std::string correo2) {
	sql::Statement *statement = NULL;
	sql::ResultSet *resultset = NULL;

	conexion->setAutoCommit(0);
	try {
		statement = conexion->createStatement();
		std::string aux = "INSERT INTO amigos VALUES('" + correo1 + "','" + correo2 + "');";
		statement->executeUpdate(aux);
		aux = "INSERT INTO amigos VALUES('" + correo2 + "','" + correo1 + "');";
		statement->executeUpdate(aux);
		aux = "DELETE FROM pendiente WHERE correo1='" + correo2 + "' AND correo2='" + correo1 + "';";
		statement->executeUpdate(aux);
		conexion->commit();
		conexion->setAutoCommit(1);
		delete statement;
		delete resultset;
		return true;
	}
	catch (sql::SQLException &e) {
		conexion->rollback();
		conexion->setAutoCommit(1);
		delete statement;
		delete resultset;
		return false;
	}
}

P2P::buscar buscar(sql::Connection* conexion, std::string nombre, std::string correo1) {
	sql::Statement *statement = NULL;
	sql::ResultSet *resultset = NULL;
	statement = conexion->createStatement();

	std::string aux;
	int i = 0, j, flag = 0, k = 0;
	P2P::buscar lista, listaaux;
	aux = "SELECT correo2 FROM amigos WHERE correo1='" + correo1 + "';";
	resultset = statement->executeQuery(aux);
	CORBA::ULong tam = listaaux.length();
	while (resultset->next()) {
		listaaux.length(tam + 1);
		listaaux[i] = resultset->getString(1).c_str();
		tam++;
		i++;
	}

	aux = "SELECT correo FROM usuarios WHERE nombre='" + nombre + "';";
	resultset = statement->executeQuery(aux);
	tam = lista.length();
	while (resultset->next()) {
		for (j = 0; j < listaaux.length(); j++) {
			if (strcmp(resultset->getString(1).c_str(), listaaux[j]) == 0) {
				flag = 1;
				cout << "Amigo encontrado!" << endl;
			}
		}
		if (flag == 0) {
			if (strcmp(correo1.c_str(), resultset->getString(1).c_str()) != 0) {
				lista.length(tam + 1);
				lista[k] = resultset->getString(1).c_str();
				tam++;
				k++;
			}
		}
		else {
			flag = 0;
		}
	}
	if (k == 0) {
		lista.length(tam + 1);
		lista[k] = "fallo@fallo.com";
	}
	
	delete statement;
	delete resultset;
	return lista;
}

bool rechazarAmig(sql::Connection* conexion, std::string correo1, std::string correo2) {
	sql::Statement *statement = NULL;
	sql::ResultSet *resultset = NULL;
	
	conexion->setAutoCommit(0);
	try {
		statement = conexion->createStatement();
		std::string aux = "DELETE FROM pendiente WHERE correo1='" + correo2 + "' AND correo2='" + correo1 + "';";
		statement->executeUpdate(aux);
		conexion->commit();
		conexion->setAutoCommit(1);
		delete statement;
		delete resultset;
		return true;
	}
	catch (sql::SQLException &e) {
		conexion->rollback();
		conexion->setAutoCommit(1);
		delete statement;
		delete resultset;
		return false;
	}
}

void avisoAmistad(sql::Connection* conexion, std::string correo1, P2P::sc_var cliente) {
	sql::Statement *statement = NULL;
	sql::ResultSet *resultset = NULL;
	
	statement = conexion->createStatement();

	std::string aux = "SELECT * FROM pendiente WHERE correo2='" + correo1 + "';";
	resultset = statement->executeQuery(aux);
	while (resultset->next()) {
		cliente->sendAmistad(resultset->getString(1).c_str());
	}
	delete statement;
	delete resultset;
}