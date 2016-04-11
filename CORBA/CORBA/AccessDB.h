#pragma once
#include "mysql_connection.h"
#include "mysql_driver.h"
#include "mysql_error.h"
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <string.h>

sql::Connection* getConexion();
void setUser(sql::Connection* conexion, std::string nombre, std::string correo, std::string pass);
int getUser(sql::Connection* conexion, std::string nombre);
void modPass(sql::Connection* conexion, std::string nombre, std::string pass);
std::string* getAmigos(sql::Connection* conexion, std::string correo);