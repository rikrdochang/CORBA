#include <omniORB4\CORBA.h>
#include <omniORB4\Naming.hh>
#include <iostream>
#include "Servidor.h"

using namespace std;

void main(int argc,char **argv){
	try {
		//Crear ORB
		CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

		//Crear POA
		CORBA::Object_var poa_obj = orb->resolve_initial_references("RootPOA");
		PortableServer::POA_var poa = PortableServer::POA::_narrow(poa_obj);
		PortableServer::POAManager_var manager = poa->the_POAManager();

		//Crear servidor
		Servidor *service = NULL;
		service = new Servidor();

		//Subir servidor a servicio de nombres
		try {
			CORBA::Object_var ns_obj = orb->resolve_initial_references("NameService");
			if (!CORBA::is_nil(ns_obj)) {
				CosNaming::NamingContext_ptr nc = CosNaming::NamingContext::_narrow(ns_obj);
				CosNaming::Name name;
				name.length(1);
				name[0].id = CORBA::string_dup("Server");
				name[0].kind = CORBA::string_dup("");
				nc->bind(name, service->_this());
				cout << "Server is running ..." << endl;
			}
		}
		catch (CosNaming::NamingContext::NotFound &) {
			cerr << "not found" << endl;
		}catch (CosNaming::NamingContext::InvalidName &) {
			cerr << "invalid name" << endl;
		}catch (CosNaming::NamingContext::CannotProceed &) {
			cerr << "cannot proceed" << endl;
		}

		manager->activate();
		orb->run();

		delete service;
		orb->destroy();
	}
	catch (CORBA::UNKNOWN) {
		cerr << "unknown exception" << endl;
	}catch (CORBA::SystemException &) {
		cerr << "system exception" << endl;
	}
	getchar();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}