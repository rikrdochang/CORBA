//
// Example code for implementing IDL interfaces in file interface.idl
//

#include <iostream>
#include <interface.hh>

//
// Example class implementing IDL interface test::test2
//
class test_test2_i : public POA_test::test2 {
private:
  // Make sure all instances are built on the heap by making the
  // destructor non-public
  //virtual ~test_test2_i();

public:
  // standard constructor
  test_test2_i();
  virtual ~test_test2_i();

  // methods corresponding to defined IDL attributes and operations
  void say_hello();
};

//
// Example implementation code for IDL interface 'test::test2'
//
test_test2_i::test_test2_i(){
  // add extra constructor code here
}
test_test2_i::~test_test2_i(){
  // add extra destructor code here
}

// Methods corresponding to IDL attributes and operations
void test_test2_i::say_hello()
{
  // insert code here and remove the warning
  #warning "Code missing in function <void test_test2_i::say_hello()>"
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
    test_test2_i* mytest_test2_i = new test_test2_i();


    // Activate the objects.  This tells the POA that the objects are
    // ready to accept requests.
    PortableServer::ObjectId_var mytest_test2_iid = poa->activate_object(mytest_test2_i);


    // Obtain a reference to each object and output the stringified
    // IOR to stdout
    {
      // IDL interface: test::test2
      CORBA::Object_var ref = mytest_test2_i->_this();
      CORBA::String_var sior(orb->object_to_string(ref));
      std::cout << "IDL object test::test2 IOR = '" << (char*)sior << "'" << std::endl;
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

