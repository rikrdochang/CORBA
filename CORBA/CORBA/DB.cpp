#include "AccessDB.h"
#include "C:\CORBA\include\omniORB4\CORBA.h"
#include "C:\CORBA\include\omniORB4\Naming.hh"
#include <iostream>

using namespace std;

void main(){
	try {
		//Creamos el objeto ORB
		CORBA::ORB_ptr orb = CORBA::ORB_init(argc, argv);
		
		//Creamos POA
		CORBA::Object_var poa_obj = orb->resolve_initial_references("RootPOA");
		PortableServer::POA_var poa = PortableServer::POA::_narrow(poa_obj);
		PortableServer::POAManager_var manager = poa->the_POAManager();

		Hello_impl *service = new Hello_impl;

		try {
			CORBA::Object_var ns_obj = orb->resolve_initial_references("NameService");
			if (!CORBA::is_nil(ns_obj)) {
				CosNaming::NamingContext_ptr nc = CosNaming::NamingContext::_narrow(ns_obj);
				CosNaming::Name name;
				name.length(1);
				name[0].id = CORBA::string_dup("TestServer");
				name[0].kind = CORBA::string_dup("");
				nc->rebind(name, service->_this());
				cout << "Server is running ..." << endl;
			}
		}
		catch (CosNaming::NamingContext::NotFound &) {
			cerr << "not found" << endl;
		}
		catch (CosNaming::NamingContext::InvalidName &) {
			cerr << "invalid name" << endl;
		}
		catch (CosNaming::NamingContext::CannotProceed &) {
			cerr << "cannot proceed" << endl;
		}

		// run
		manager->activate();
		orb->run();

		// clean up
		delete service;

		// quit
		orb->destroy();
	}
	catch (CORBA::UNKNOWN) {
		cerr << "unknown exception" << endl;
	}
	catch (CORBA::SystemException &) {
		cerr << "system exception" << endl;
	}

	sql::Connection *connection;
	connection = getConexion();

	setUser(connection,"Bruno","bruno@correo.com","pene");
	
	delete connection;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}