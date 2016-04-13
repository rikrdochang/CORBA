//
// Example code for implementing IDL interfaces in file interface.idl
//

#include <iostream>
#include <interface.hh>

//
// Example class implementing IDL interface P2P::cc
//
class P2P_cc_i : public POA_P2P::cc {
private:
  // Make sure all instances are built on the heap by making the
  // destructor non-public
  //virtual ~P2P_cc_i();

public:
  // standard constructor
  P2P_cc_i();
  virtual ~P2P_cc_i();

  // methods corresponding to defined IDL attributes and operations
  void talk(const char* mensaje);
};

//
// Example implementation code for IDL interface 'P2P::cc'
//
P2P_cc_i::P2P_cc_i(){
  // add extra constructor code here
}
P2P_cc_i::~P2P_cc_i(){
  // add extra destructor code here
}

// Methods corresponding to IDL attributes and operations
void P2P_cc_i::talk(const char* mensaje)
{
  // insert code here and remove the warning
  #warning "Code missing in function <void P2P_cc_i::talk(const char* mensaje)>"
}



// End of example implementation code

//
// Example class implementing IDL interface P2P::sc
//
class P2P_sc_i : public POA_P2P::sc {
private:
  // Make sure all instances are built on the heap by making the
  // destructor non-public
  //virtual ~P2P_sc_i();

public:
  // standard constructor
  P2P_sc_i();
  virtual ~P2P_sc_i();

  // methods corresponding to defined IDL attributes and operations
  void sendAmistad(const char* correo);
  void notificar(const char* correo, ::CORBA::Boolean estado);
};

//
// Example implementation code for IDL interface 'P2P::sc'
//
P2P_sc_i::P2P_sc_i(){
  // add extra constructor code here
}
P2P_sc_i::~P2P_sc_i(){
  // add extra destructor code here
}

// Methods corresponding to IDL attributes and operations
void P2P_sc_i::sendAmistad(const char* correo)
{
  // insert code here and remove the warning
  #warning "Code missing in function <void P2P_sc_i::sendAmistad(const char* correo)>"
}

void P2P_sc_i::notificar(const char* correo, ::CORBA::Boolean estado)
{
  // insert code here and remove the warning
  #warning "Code missing in function <void P2P_sc_i::notificar(const char* correo, ::CORBA::Boolean estado)>"
}



// End of example implementation code

//
// Example class implementing IDL interface P2P::cs
//
class P2P_cs_i : public POA_P2P::cs {
private:
  // Make sure all instances are built on the heap by making the
  // destructor non-public
  //virtual ~P2P_cs_i();

public:
  // standard constructor
  P2P_cs_i();
  virtual ~P2P_cs_i();

  // methods corresponding to defined IDL attributes and operations
  void pedirAmistad(const char* correo1, const char* correo2);
  P2P::amigos* logueo(const char* correo, const char* pass);
  ::CORBA::Boolean registro(const char* correo, const char* pass, const char* nombre);
  ::CORBA::Boolean desregistro(const char* correo);
  ::CORBA::Boolean modPass(const char* correo, const char* pass1, const char* pass2);
  ::CORBA::Boolean deslogueo(const char* correo);
  ::CORBA::Boolean aceptarAmistad(const char* correo1, const char* correo2);
  P2P::buscar* buscaAmigos(const char* nombre);
};

//
// Example implementation code for IDL interface 'P2P::cs'
//
P2P_cs_i::P2P_cs_i(){
  // add extra constructor code here
}
P2P_cs_i::~P2P_cs_i(){
  // add extra destructor code here
}

// Methods corresponding to IDL attributes and operations
void P2P_cs_i::pedirAmistad(const char* correo1, const char* correo2)
{
  // insert code here and remove the warning
  #warning "Code missing in function <void P2P_cs_i::pedirAmistad(const char* correo1, const char* correo2)>"
}

P2P::amigos* P2P_cs_i::logueo(const char* correo, const char* pass)
{
  // insert code here and remove the warning
  #warning "Code missing in function <P2P::amigos* P2P_cs_i::logueo(const char* correo, const char* pass)>"
}

::CORBA::Boolean P2P_cs_i::registro(const char* correo, const char* pass, const char* nombre)
{
  // insert code here and remove the warning
  #warning "Code missing in function <::CORBA::Boolean P2P_cs_i::registro(const char* correo, const char* pass, const char* nombre)>"
}

::CORBA::Boolean P2P_cs_i::desregistro(const char* correo)
{
  // insert code here and remove the warning
  #warning "Code missing in function <::CORBA::Boolean P2P_cs_i::desregistro(const char* correo)>"
}

::CORBA::Boolean P2P_cs_i::modPass(const char* correo, const char* pass1, const char* pass2)
{
  // insert code here and remove the warning
  #warning "Code missing in function <::CORBA::Boolean P2P_cs_i::modPass(const char* correo, const char* pass1, const char* pass2)>"
}

::CORBA::Boolean P2P_cs_i::deslogueo(const char* correo)
{
  // insert code here and remove the warning
  #warning "Code missing in function <::CORBA::Boolean P2P_cs_i::deslogueo(const char* correo)>"
}

::CORBA::Boolean P2P_cs_i::aceptarAmistad(const char* correo1, const char* correo2)
{
  // insert code here and remove the warning
  #warning "Code missing in function <::CORBA::Boolean P2P_cs_i::aceptarAmistad(const char* correo1, const char* correo2)>"
}

P2P::buscar* P2P_cs_i::buscaAmigos(const char* nombre)
{
  // insert code here and remove the warning
  #warning "Code missing in function <P2P::buscar* P2P_cs_i::buscaAmigos(const char* nombre)>"
}



// End of example implementation code



int main(int argc, char** argv)
{
  try {
    // Initialise the ORB.
    CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

    // Obtain a reference to the root POA.
    CORBA::Object_var obj = orb->resolve_initial_references("RootPOA");
    PortableServer::POA_var poa = PortableServer::POA::_narrow(obj);

    // We allocate the objects on the heap.  Since these are reference
    // counted objects, they will be deleted by the POA when they are no
    // longer needed.
    P2P_cc_i* myP2P_cc_i = new P2P_cc_i();
    P2P_sc_i* myP2P_sc_i = new P2P_sc_i();
    P2P_cs_i* myP2P_cs_i = new P2P_cs_i();


    // Activate the objects.  This tells the POA that the objects are
    // ready to accept requests.
    PortableServer::ObjectId_var myP2P_cc_iid = poa->activate_object(myP2P_cc_i);
    PortableServer::ObjectId_var myP2P_sc_iid = poa->activate_object(myP2P_sc_i);
    PortableServer::ObjectId_var myP2P_cs_iid = poa->activate_object(myP2P_cs_i);


    // Obtain a reference to each object and output the stringified
    // IOR to stdout
    {
      // IDL interface: P2P::cc
      CORBA::Object_var ref = myP2P_cc_i->_this();
      CORBA::String_var sior(orb->object_to_string(ref));
      std::cout << "IDL object P2P::cc IOR = '" << (char*)sior << "'" << std::endl;
    }

    {
      // IDL interface: P2P::sc
      CORBA::Object_var ref = myP2P_sc_i->_this();
      CORBA::String_var sior(orb->object_to_string(ref));
      std::cout << "IDL object P2P::sc IOR = '" << (char*)sior << "'" << std::endl;
    }

    {
      // IDL interface: P2P::cs
      CORBA::Object_var ref = myP2P_cs_i->_this();
      CORBA::String_var sior(orb->object_to_string(ref));
      std::cout << "IDL object P2P::cs IOR = '" << (char*)sior << "'" << std::endl;
    }



    // Obtain a POAManager, and tell the POA to start accepting
    // requests on its objects.
    PortableServer::POAManager_var pman = poa->the_POAManager();
    pman->activate();

    orb->run();
    orb->destroy();
  }
  catch(CORBA::TRANSIENT&) {
    std::cerr << "Caught system exception TRANSIENT -- unable to contact the "
              << "server." << std::endl;
  }
  catch(CORBA::SystemException& ex) {
    std::cerr << "Caught a CORBA::" << ex._name() << std::endl;
  }
  catch(CORBA::Exception& ex) {
    std::cerr << "Caught CORBA::Exception: " << ex._name() << std::endl;
  }
  return 0;
}

