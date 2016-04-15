/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package P2P;

import cliente.Chat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.omg.CORBA.ORB;
import org.omg.CosNaming.NamingContextPackage.CannotProceed;
import org.omg.CosNaming.NamingContextPackage.InvalidName;
import org.omg.CosNaming.NamingContextPackage.NotFound;

/**
 *
 * @author brunis46
 */
public class ccServant extends ccPOA {

    private HashMap<String, Chat> chatsAmigos;
    private org.omg.CORBA.ORB orb;
    private String correo;

    public ccServant(ORB orb, String mail, HashMap<String, Chat> camig) {
        this.orb = orb;
        this.correo = mail;
        this.chatsAmigos = camig;
    }

    @Override
    public void talk(String mensaje) {
        
        Calendar calendario = new GregorianCalendar();
        c.getMensajes().setText(c.getMensajes().getText() + "\n" + correo2 + "("
                + calendario.get(Calendar.HOUR_OF_DAY)
                + ":" + calendario.get(Calendar.MINUTE)
                + "):      " + mensaje);
    }

    @Override
    public void init(String correo2) {


        Chat aux = chatsAmigos.get(correo2);
        try {
            if (aux == null) {
                String ruta = correo2 + "cc";
                org.omg.CORBA.Object ns_obj = orb.resolve_initial_references("NameService");
                org.omg.CosNaming.NamingContext nc = org.omg.CosNaming.NamingContextHelper.narrow(ns_obj);
                org.omg.CosNaming.NameComponent[] path = {new org.omg.CosNaming.NameComponent(ruta, "")};
                org.omg.CORBA.Object obj = nc.resolve(path);
                cc amig = ccHelper.narrow(obj);

                aux = new Chat(amig, correo, correo2);
                aux.getNombre().setText("Conversación de " + correo + " con " + correo2);
            } else {
                aux.setVisible(true);
            }

        } catch (NotFound ex) {
            Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
        } catch (CannotProceed ex) {
            Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
        } catch (InvalidName ex) {
            Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
        } catch (org.omg.CORBA.ORBPackage.InvalidName ex) {
            Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}
