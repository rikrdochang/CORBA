#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>

#pragma comment(lib, "mysqlcppconn.lib")

void main(){
	sql::Driver *driver;
	sql::Connection *connection;
	sql::Statement *statement;
	sql::ResultSet *resultset;

	//Conexión a MySQL
	driver = get_driver_instance();
	connection = driver->connect("tcp://127.0.0.1:3306", "lueiro", "0612");

	//Use PDB;
	connection->setSchema("PDB");

	//Consulta
	statement = connection->createStatement();
	resultset = statement->executeQuery("SELECT * FROM usuarios");

	//Print
	while (resultset->next()) {
		std::cout << "Correo: " << resultset->getString(1);
		std::cout << "\n Nombre: " << resultset->getString(2);
		std::cout << std::endl;
	}

	// Edit (La consulta lanza una excepción con un error tipo 0 (éxito))
	try {
		statement->executeQuery("UPDATE usuarios SET correo=primero@correo.es WHERE correo=primero@correo.com");
	}catch (sql::SQLException &e) {}

	//Frees
	delete resultset;
	delete statement;
	delete connection;
}