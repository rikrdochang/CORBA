package P2P;

/**
* P2P/csHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* mi�rcoles 13 de abril de 2016 20H56' CEST
*/

public final class csHolder implements org.omg.CORBA.portable.Streamable
{
  public P2P.cs value = null;

  public csHolder ()
  {
  }

  public csHolder (P2P.cs initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = P2P.csHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    P2P.csHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return P2P.csHelper.type ();
  }

}
