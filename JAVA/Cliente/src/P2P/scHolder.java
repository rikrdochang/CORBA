package P2P;

/**
* P2P/scHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* s�bado 16 de abril de 2016 18H31' CEST
*/

public final class scHolder implements org.omg.CORBA.portable.Streamable
{
  public P2P.sc value = null;

  public scHolder ()
  {
  }

  public scHolder (P2P.sc initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = P2P.scHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    P2P.scHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return P2P.scHelper.type ();
  }

}
