package P2P;

/**
* P2P/amigoHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* s�bado 16 de abril de 2016 18H31' CEST
*/

public final class amigoHolder implements org.omg.CORBA.portable.Streamable
{
  public P2P.amigo value = null;

  public amigoHolder ()
  {
  }

  public amigoHolder (P2P.amigo initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = P2P.amigoHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    P2P.amigoHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return P2P.amigoHelper.type ();
  }

}
