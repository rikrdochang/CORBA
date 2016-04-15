#pragma once
#include "mysql_connection.h"
#include "mysql_driver.h"
#include "mysql_error.h"
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <string.h>
#include "interface.hh"
#include <stdio.h>
#include <iostream>
#include <omniORB4\CORBA.h>
#include <omniORB4\Naming.hh>
#include <iostream>

sql::Connection* getConexion();
bool setUser(sql::Connection* conexion, std::string nombre, std::string correo, std::string pass);
bool getUser(sql::Connection* conexion, std::string nombre, std::string pass);
bool delUser(sql::Connection* conexion, std::string correo);
bool chgPass(sql::Connection* conexion, std::string correo, std::string pass1, std::string pass2);
P2P::amigos getAmigos(sql::Connection* conexion, std::string correo, P2P::amigos);
void preAmistad(sql::Connection* conexion, std::string correo1, std::string correo2);
bool amistad(sql::Connection* conexion, std::string correo1, std::string correo2);
P2P::buscar buscar(sql::Connection* conexion, std::string nombre);