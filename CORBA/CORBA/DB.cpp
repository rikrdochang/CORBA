#include "mysql_connection.h"
#include "mysql_driver.h"
#include "mysql_error.h"
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>

void main(){
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *connection;
	sql::Statement *statement;
	sql::ResultSet *resultset;

	//Conexión a MySQL
	driver = sql::mysql::get_mysql_driver_instance();
	connection = driver->connect("tcp://localhost:3306/PDB", "lueiro", "0612");

	//Consulta
	statement = connection->createStatement();
	resultset = statement->executeQuery("SELECT * FROM usuarios;");

	//Print
	while (resultset->next()) {
		std::cout << "Correo: " << resultset->getString(1);
		std::cout << "\n Nombre: " << resultset->getString(2);
		std::cout << std::endl;
	}
	// Edit (La consulta lanza una excepción con un error tipo 0 (éxito))
	try {
		statement->executeQuery("UPDATE usuarios SET correo='primero@correo.com' WHERE correo='primero@correo.es';");
	}catch (sql::SQLException &e) {}

	//Frees
	delete resultset;
	delete statement;
	delete connection;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}