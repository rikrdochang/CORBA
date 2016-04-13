package P2P;


/**
* P2P/csPOA.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* mi�rcoles 13 de abril de 2016 20H27' CEST
*/

public abstract class csPOA extends org.omg.PortableServer.Servant
 implements P2P.csOperations, org.omg.CORBA.portable.InvokeHandler
{

  // Constructors

  private static java.util.Hashtable _methods = new java.util.Hashtable ();
  static
  {
    _methods.put ("pedirAmistad", new java.lang.Integer (0));
    _methods.put ("logueo", new java.lang.Integer (1));
    _methods.put ("registro", new java.lang.Integer (2));
    _methods.put ("desregistro", new java.lang.Integer (3));
    _methods.put ("modPass", new java.lang.Integer (4));
    _methods.put ("deslogueo", new java.lang.Integer (5));
    _methods.put ("aceptarAmistad", new java.lang.Integer (6));
    _methods.put ("buscaAmigos", new java.lang.Integer (7));
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
       case 0:  // P2P/cs/pedirAmistad
       {
         String correo1 = in.read_string ();
         String correo2 = in.read_string ();
         this.pedirAmistad (correo1, correo2);
         out = $rh.createReply();
         break;
       }

       case 1:  // P2P/cs/logueo
       {
         String correo = in.read_string ();
         String pass = in.read_string ();
         P2P.sc tmp = P2P.scHelper.read (in);
         P2P.cc aux = P2P.ccHelper.read (in);
         P2P.amigo $result[] = null;
         $result = this.logueo (correo, pass, tmp, aux);
         out = $rh.createReply();
         P2P.amigosHelper.write (out, $result);
         break;
       }

       case 2:  // P2P/cs/registro
       {
         String correo = in.read_string ();
         String pass = in.read_string ();
         String nombre = in.read_string ();
         boolean $result = false;
         $result = this.registro (correo, pass, nombre);
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 3:  // P2P/cs/desregistro
       {
         String correo = in.read_string ();
         boolean $result = false;
         $result = this.desregistro (correo);
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 4:  // P2P/cs/modPass
       {
         String correo = in.read_string ();
         String pass1 = in.read_string ();
         String pass2 = in.read_string ();
         boolean $result = false;
         $result = this.modPass (correo, pass1, pass2);
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 5:  // P2P/cs/deslogueo
       {
         String correo = in.read_string ();
         P2P.sc aux = P2P.scHelper.read (in);
         boolean $result = false;
         $result = this.deslogueo (correo, aux);
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 6:  // P2P/cs/aceptarAmistad
       {
         String correo1 = in.read_string ();
         String correo2 = in.read_string ();
         boolean $result = false;
         $result = this.aceptarAmistad (correo1, correo2);
         out = $rh.createReply();
         out.write_boolean ($result);
         break;
       }

       case 7:  // P2P/cs/buscaAmigos
       {
         String nombre = in.read_string ();
         String $result[] = null;
         $result = this.buscaAmigos (nombre);
         out = $rh.createReply();
         P2P.buscarHelper.write (out, $result);
         break;
       }

       default:
         throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);
    }

    return out;
  } // _invoke

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:P2P/cs:1.0"};

  public String[] _all_interfaces (org.omg.PortableServer.POA poa, byte[] objectId)
  {
    return (String[])__ids.clone ();
  }

  public cs _this() 
  {
    return csHelper.narrow(
    super._this_object());
  }

  public cs _this(org.omg.CORBA.ORB orb) 
  {
    return csHelper.narrow(
    super._this_object(orb));
  }


} // class csPOA
