package P2P;


/**
* P2P/amigo.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* domingo 17 de abril de 2016 04H16' CEST
*/

public final class amigo implements org.omg.CORBA.portable.IDLEntity
{
  public String correo = null;
  public boolean estado = false;

  public amigo ()
  {
  } // ctor

  public amigo (String _correo, boolean _estado)
  {
    correo = _correo;
    estado = _estado;
  } // ctor

} // class amigo
