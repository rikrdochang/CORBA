package P2P;

/**
* P2P/ccHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* domingo 17 de abril de 2016 18H33' CEST
*/

public final class ccHolder implements org.omg.CORBA.portable.Streamable
{
  public P2P.cc value = null;

  public ccHolder ()
  {
  }

  public ccHolder (P2P.cc initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = P2P.ccHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    P2P.ccHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return P2P.ccHelper.type ();
  }

}
