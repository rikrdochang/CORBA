#include "AccessDB.h"

void main(){
	sql::Connection *connection;
	connection = getConexion();

	setUser(connection,"Bruno","bruno@correo.com","pene");
	
	delete connection;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}