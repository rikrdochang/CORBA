package P2P;


/**
* P2P/buscarHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* domingo 17 de abril de 2016 03H04' CEST
*/

public final class buscarHolder implements org.omg.CORBA.portable.Streamable
{
  public String value[] = null;

  public buscarHolder ()
  {
  }

  public buscarHolder (String[] initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = P2P.buscarHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    P2P.buscarHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return P2P.buscarHelper.type ();
  }

}
