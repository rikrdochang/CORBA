package P2P;


/**
* P2P/amigosHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* viernes 15 de abril de 2016 20H14' CEST
*/

abstract public class amigosHelper
{
  private static String  _id = "IDL:P2P/amigos:1.0";

  public static void insert (org.omg.CORBA.Any a, P2P.amigo[] that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static P2P.amigo[] extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      __typeCode = P2P.amigoHelper.type ();
      __typeCode = org.omg.CORBA.ORB.init ().create_sequence_tc (0, __typeCode);
      __typeCode = org.omg.CORBA.ORB.init ().create_alias_tc (P2P.amigosHelper.id (), "amigos", __typeCode);
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static P2P.amigo[] read (org.omg.CORBA.portable.InputStream istream)
  {
    P2P.amigo value[] = null;
    int _len0 = istream.read_long ();
    value = new P2P.amigo[_len0];
    for (int _o1 = 0;_o1 < value.length; ++_o1)
      value[_o1] = P2P.amigoHelper.read (istream);
    return value;
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, P2P.amigo[] value)
  {
    ostream.write_long (value.length);
    for (int _i0 = 0;_i0 < value.length; ++_i0)
      P2P.amigoHelper.write (ostream, value[_i0]);
  }

}
