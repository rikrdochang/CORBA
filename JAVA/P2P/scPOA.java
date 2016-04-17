package P2P;


/**
* P2P/scPOA.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* domingo 17 de abril de 2016 04H16' CEST
*/

public abstract class scPOA extends org.omg.PortableServer.Servant
 implements P2P.scOperations, org.omg.CORBA.portable.InvokeHandler
{

  // Constructors

  private static java.util.Hashtable _methods = new java.util.Hashtable ();
  static
  {
    _methods.put ("sendAmistad", new java.lang.Integer (0));
    _methods.put ("notificar", new java.lang.Integer (1));
  }

  public org.omg.CORBA.portable.OutputStream _invoke (String $method,
                                org.omg.CORBA.portable.InputStream in,
                                org.omg.CORBA.portable.ResponseHandler $rh)
  {
    org.omg.CORBA.portable.OutputStream out = null;
    java.lang.Integer __method = (java.lang.Integer)_methods.get ($method);
    if (__method == null)
      throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);

    switch (__method.intValue ())
    {
       case 0:  // P2P/sc/sendAmistad
       {
         String correo = in.read_string ();
         this.sendAmistad (correo);
         out = $rh.createReply();
         break;
       }

       case 1:  // P2P/sc/notificar
       {
         String correo = in.read_string ();
         boolean estado = in.read_boolean ();
         this.notificar (correo, estado);
         out = $rh.createReply();
         break;
       }

       default:
         throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);
    }

    return out;
  } // _invoke

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:P2P/sc:1.0"};

  public String[] _all_interfaces (org.omg.PortableServer.POA poa, byte[] objectId)
  {
    return (String[])__ids.clone ();
  }

  public sc _this() 
  {
    return scHelper.narrow(
    super._this_object());
  }

  public sc _this(org.omg.CORBA.ORB orb) 
  {
    return scHelper.narrow(
    super._this_object(orb));
  }


} // class scPOA
