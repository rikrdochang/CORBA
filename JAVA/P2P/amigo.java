package P2P;


/**
* P2P/amigo.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* mi�rcoles 13 de abril de 2016 20H56' CEST
*/

public final class amigo implements org.omg.CORBA.portable.IDLEntity
{
  public String correo = null;
  public P2P.cc instancia = null;
  public boolean estado = false;

  public amigo ()
  {
  } // ctor

  public amigo (String _correo, P2P.cc _instancia, boolean _estado)
  {
    correo = _correo;
    instancia = _instancia;
    estado = _estado;
  } // ctor

} // class amigo
