package P2P;


/**
* P2P/csHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* mi�rcoles 13 de abril de 2016 19H10' CEST
*/

abstract public class csHelper
{
  private static String  _id = "IDL:P2P/cs:1.0";

  public static void insert (org.omg.CORBA.Any a, P2P.cs that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static P2P.cs extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      __typeCode = org.omg.CORBA.ORB.init ().create_interface_tc (P2P.csHelper.id (), "cs");
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static P2P.cs read (org.omg.CORBA.portable.InputStream istream)
  {
    return narrow (istream.read_Object (_csStub.class));
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, P2P.cs value)
  {
    ostream.write_Object ((org.omg.CORBA.Object) value);
  }

  public static P2P.cs narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof P2P.cs)
      return (P2P.cs)obj;
    else if (!obj._is_a (id ()))
      throw new org.omg.CORBA.BAD_PARAM ();
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      P2P._csStub stub = new P2P._csStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

  public static P2P.cs unchecked_narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof P2P.cs)
      return (P2P.cs)obj;
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      P2P._csStub stub = new P2P._csStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

}
