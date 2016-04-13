#pragma once
#include "mysql_connection.h"
#include "mysql_driver.h"
#include "mysql_error.h"
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <string.h>

sql::Connection* getConexion();
bool setUser(sql::Connection* conexion, std::string nombre, std::string correo, std::string pass);
bool getUser(sql::Connection* conexion, std::string nombre, std::string pass);
void modPass(sql::Connection* conexion, std::string nombre, std::string pass);
P2P::amigos getAmigos(sql::Connection* conexion, std::string correo, P2P::amigos);
void preAmistad(sql::Connection* conexion, std::string correo1, std::string correo2);