package P2P;


/**
* P2P/amigo.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* mi�rcoles 13 de abril de 2016 19H10' CEST
*/

public final class amigo implements org.omg.CORBA.portable.IDLEntity
{
  public String correo = null;
  public String ip = null;

  public amigo ()
  {
  } // ctor

  public amigo (String _correo, String _ip)
  {
    correo = _correo;
    ip = _ip;
  } // ctor

} // class amigo
