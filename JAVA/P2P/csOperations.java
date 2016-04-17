package P2P;


/**
* P2P/csOperations.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from interface.idl
* domingo 17 de abril de 2016 03H04' CEST
*/

public interface csOperations 
{
  boolean pedirAmistad (String correo1, String correo2);
  P2P.amigo[] logueo (String correo, String pass);
  boolean registro (String correo, String pass, String nombre);
  boolean desregistro (String correo);
  boolean modPass (String correo, String pass1, String pass2);
  boolean deslogueo (String correo);
  boolean aceptarAmistad (String correo1, String correo2);
  String[] buscaAmigos (String nombre, String correo);
  boolean noAmistad (String correo1, String correo2);
  void initAmistad (String correo1);
} // interface csOperations
