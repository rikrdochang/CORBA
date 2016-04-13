package P2P;


/**
* P2P/_csStub.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* mi�rcoles 13 de abril de 2016 18H48' CEST
*/

public class _csStub extends org.omg.CORBA.portable.ObjectImpl implements P2P.cs
{

  public void pedirAmistad (String correo)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("pedirAmistad", true);
                $out.write_string (correo);
                $in = _invoke ($out);
                return;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                pedirAmistad (correo        );
            } finally {
                _releaseReply ($in);
            }
  } // pedirAmistad

  public P2P.amigo[] logueo (String correo, String pass, P2P.sc tmp)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("logueo", true);
                $out.write_string (correo);
                $out.write_string (pass);
                P2P.scHelper.write ($out, tmp);
                $in = _invoke ($out);
                P2P.amigo $result[] = P2P.amigosHelper.read ($in);
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return logueo (correo, pass, tmp        );
            } finally {
                _releaseReply ($in);
            }
  } // logueo

  public boolean registro (String correo, String pass, String nombre)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("registro", true);
                $out.write_string (correo);
                $out.write_string (pass);
                $out.write_string (nombre);
                $in = _invoke ($out);
                boolean $result = $in.read_boolean ();
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return registro (correo, pass, nombre        );
            } finally {
                _releaseReply ($in);
            }
  } // registro

  public boolean modPass (String correo, String pass1, String pass2)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("modPass", true);
                $out.write_string (correo);
                $out.write_string (pass1);
                $out.write_string (pass2);
                $in = _invoke ($out);
                boolean $result = $in.read_boolean ();
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return modPass (correo, pass1, pass2        );
            } finally {
                _releaseReply ($in);
            }
  } // modPass

  public boolean deslogueo (String correo, P2P.sc aux)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("deslogueo", true);
                $out.write_string (correo);
                P2P.scHelper.write ($out, aux);
                $in = _invoke ($out);
                boolean $result = $in.read_boolean ();
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return deslogueo (correo, aux        );
            } finally {
                _releaseReply ($in);
            }
  } // deslogueo

  public boolean aceptarAmistad (String correo)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("aceptarAmistad", true);
                $out.write_string (correo);
                $in = _invoke ($out);
                boolean $result = $in.read_boolean ();
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return aceptarAmistad (correo        );
            } finally {
                _releaseReply ($in);
            }
  } // aceptarAmistad

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:P2P/cs:1.0"};

  public String[] _ids ()
  {
    return (String[])__ids.clone ();
  }

  private void readObject (java.io.ObjectInputStream s) throws java.io.IOException
  {
     String str = s.readUTF ();
     String[] args = null;
     java.util.Properties props = null;
     org.omg.CORBA.ORB orb = org.omg.CORBA.ORB.init (args, props);
   try {
     org.omg.CORBA.Object obj = orb.string_to_object (str);
     org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl) obj)._get_delegate ();
     _set_delegate (delegate);
   } finally {
     orb.destroy() ;
   }
  }

  private void writeObject (java.io.ObjectOutputStream s) throws java.io.IOException
  {
     String[] args = null;
     java.util.Properties props = null;
     org.omg.CORBA.ORB orb = org.omg.CORBA.ORB.init (args, props);
   try {
     String str = orb.object_to_string (this);
     s.writeUTF (str);
   } finally {
     orb.destroy() ;
   }
  }
} // class _csStub
