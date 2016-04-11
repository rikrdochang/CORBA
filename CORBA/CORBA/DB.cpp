#include "AccessDB.h"
#include <omniORB4\CORBA.h>
#include <omniORB4\Naming.hh>
#include <iostream>
#include "Hello_Impl.h"

using namespace std;
static CORBA::Boolean bindObjectToName(CORBA::ORB_ptr, CORBA::Object_ptr, const char *name);

void main(int argc,char **argv){
	try {
		// init ORB
		CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

		// init POA
		CORBA::Object_var poa_obj = orb->resolve_initial_references("RootPOA");
		PortableServer::POA_var poa = PortableServer::POA::_narrow(poa_obj);
		PortableServer::POAManager_var manager = poa->the_POAManager();

		// create service
		Hello_impl *service = new Hello_impl;

		// register within the naming service
		try {
			CORBA::Object_var ns_obj = orb->resolve_initial_references("NameService");
			if (!CORBA::is_nil(ns_obj)) {
				CosNaming::NamingContext_ptr nc = CosNaming::NamingContext::_narrow(ns_obj);
				CosNaming::Name name;
				name.length(1);
				name[0].id = CORBA::string_dup("TestServer");
				name[0].kind = CORBA::string_dup("");
				//nc->bind(name, service->say_hello());
				bindObjectToName(orb, poa_obj,"hola");
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
	/*
	sql::Connection *connection;
	connection = getConexion();

	setUser(connection,"Bruno","bruno@correo.com","pene");
	
	delete connection;
	*/
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static CORBA::Boolean bindObjectToName(CORBA::ORB_ptr orb, CORBA::Object_ptr objref, const char* name) {
	CosNaming::NamingContext_var rootContext;
	try {
		CORBA::Object_var obj = orb->resolve_initial_references("NameService");
		rootContext = CosNaming::NamingContext::_narrow(obj);
		if (CORBA::is_nil(rootContext)) {
			cerr << "Failed to narrow the root naming context." << endl;
			return 0;
		}
	}
	catch (CORBA::NO_RESOURCES&) {
		cerr << "Caught NO_RESOURCES exception. You must configure omniORB " << "with the location" << endl << "of the naming service." << endl;
		return 0;
	}
	catch (CORBA::ORB::InvalidName&) {
		cerr << "Service required is invalid [does not exist]." << endl;
		return 0;
	}
	try {
		CosNaming::Name contextName;
		contextName.length(1);
		contextName[0].id = (const char*) "test";       // string copied
		contextName[0].kind = (const char*) "my_context"; // string copied
		CosNaming::NamingContext_var testContext;
		try {
			testContext = rootContext->bind_new_context(contextName);
		}
		catch (CosNaming::NamingContext::AlreadyBound& ex) {
			CORBA::Object_var obj = rootContext->resolve(contextName);
			testContext = CosNaming::NamingContext::_narrow(obj);
			if (CORBA::is_nil(testContext)) {
				cerr << "Failed to narrow naming context." << endl;
				return 0;
			}
		}
		CosNaming::Name objectName;
		objectName.length(1);
		objectName[0].id = name;   // string copied
		//objectName[0].kind = (const char*) "Object"; // string copied
		try {
			testContext->bind(objectName, objref);
		}
		catch (CosNaming::NamingContext::AlreadyBound& ex) {
			testContext->rebind(objectName, objref);
		}
	}
	catch (CORBA::TRANSIENT& ex) {
		cerr << "Caught system exception TRANSIENT -- unable to contact the " << "naming service." << endl << "Make sure the naming server is running and that omniORB is " << "configured correctly." << endl;
		return 0;
	}
	catch (CORBA::SystemException& ex) {
		cerr << "Caught a CORBA::" << ex._name() << " while using the naming service." << endl;
		return 0;
	}
	return 1;
}