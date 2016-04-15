/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package P2P;

import cliente.Chat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.omg.CORBA.ORB;
import org.omg.CosNaming.NamingContextPackage.CannotProceed;
import org.omg.CosNaming.NamingContextPackage.InvalidName;
import org.omg.CosNaming.NamingContextPackage.NotFound;
import org.omg.PortableServer.POA;

/**
 *
 * @author brunis46
 */
public class ccServant extends ccPOA {

    private Chat c;
    private org.omg.CORBA.ORB orb;

    public ccServant(ORB orb) {
        this.orb = orb;
    }

    public void inicializar(String correo) {
        try {
            String ruta = correo + "cc";
            org.omg.CORBA.Object ns_obj = orb.resolve_initial_references("NameService");
            org.omg.CosNaming.NamingContext nc = org.omg.CosNaming.NamingContextHelper.narrow(ns_obj);
            org.omg.CosNaming.NameComponent[] path = {new org.omg.CosNaming.NameComponent(ruta, "")};
            org.omg.CORBA.Object obj = nc.resolve(path);
            cc amig = ccHelper.narrow(obj);

            c = new Chat();
            c.setAmigo(amig);
            c.setCorreo(correo);
            
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

    @Override
    public void talk(String mensaje) {
        if (!c.isVisible()) {
            c.setVisible(true);
        }
        Calendar calendario = new GregorianCalendar();
        c.getMensajes().setText(c.getMensajes().getText() + "\n" + c.getCorreo() + "("
                + calendario.get(Calendar.HOUR_OF_DAY)
                + ":" + calendario.get(Calendar.MINUTE)
                + "):      " + mensaje);
    }

}
