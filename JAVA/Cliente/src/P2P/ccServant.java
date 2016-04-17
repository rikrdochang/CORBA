package P2P;

import cliente.Chat;
import cliente.Principal;
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

    private Principal p;
    private org.omg.CORBA.ORB orb;
    private String correo;

    public ccServant(ORB orb, String mail, Principal paux) {
        this.orb = orb;
        this.correo = mail;
        p = paux;
    }

    @Override
    public void init(String correo2) {

        Chat aux = p.getChatsAmigos().get(correo2);
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
                aux.setVisible(true);
                p.getChatsAmigos().put(correo2, aux);
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

    @Override
    public void talk(String correo2, String mensaje) {

        Chat tmp = p.getChatsAmigos().get(correo2);

        if (tmp == null) {
            try {
                String ruta = correo2 + "cc";
                org.omg.CORBA.Object ns_obj = orb.resolve_initial_references("NameService");
                org.omg.CosNaming.NamingContext nc = org.omg.CosNaming.NamingContextHelper.narrow(ns_obj);
                org.omg.CosNaming.NameComponent[] path = {new org.omg.CosNaming.NameComponent(ruta, "")};
                org.omg.CORBA.Object obj = nc.resolve(path);
                cc amig = ccHelper.narrow(obj);

                tmp = new Chat(amig, correo, correo2);
                tmp.setVisible(true);
                p.getChatsAmigos().put(correo2, tmp);
            } catch (org.omg.CORBA.ORBPackage.InvalidName ex) {
                Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
            } catch (NotFound ex) {
                Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
            } catch (CannotProceed ex) {
                Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
            } catch (InvalidName ex) {
                Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
            }
        } else {
            if (!tmp.isVisible()) {
                p.getChatsAmigos().get(correo2).setVisible(true);
            }
        }
        Calendar calendario = new GregorianCalendar();
        tmp.getMensajes().setText(tmp.getMensajes().getText() + "\n\n" + correo2 + "("
                + calendario.get(Calendar.HOUR_OF_DAY)
                + ":" + calendario.get(Calendar.MINUTE)
                + "):      " + mensaje);
        tmp.getMensajes().setCaretPosition(tmp.getMensajes().getDocument().getLength());
    }

    @Override
    public void enviarArchivo(String correo1, String nombreArchivo, byte[] archivo) {
        Chat tmp = p.getChatsAmigos().get(correo1);

        if (tmp == null) {
            try {
                String ruta = correo1 + "cc";
                org.omg.CORBA.Object ns_obj = orb.resolve_initial_references("NameService");
                org.omg.CosNaming.NamingContext nc = org.omg.CosNaming.NamingContextHelper.narrow(ns_obj);
                org.omg.CosNaming.NameComponent[] path = {new org.omg.CosNaming.NameComponent(ruta, "")};
                org.omg.CORBA.Object obj = nc.resolve(path);
                cc amig = ccHelper.narrow(obj);

                tmp = new Chat(amig, correo, correo1);
                tmp.setVisible(true);
                p.getChatsAmigos().put(correo1, tmp);
            } catch (org.omg.CORBA.ORBPackage.InvalidName ex) {
                Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
            } catch (NotFound ex) {
                Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
            } catch (CannotProceed ex) {
                Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
            } catch (InvalidName ex) {
                Logger.getLogger(ccServant.class.getName()).log(Level.SEVERE, null, ex);
            }
        } else {
            if (!tmp.isVisible()) {
                p.getChatsAmigos().get(correo1).setVisible(true);
            }
        }

        // CAMBIAR
        tmp.createFile(nombreArchivo, archivo, correo);

        Calendar calendario = new GregorianCalendar();
        tmp.getMensajes().setText(tmp.getMensajes().getText() + "\n\n" + correo1 + "("
                + calendario.get(Calendar.HOUR_OF_DAY)
                + ":" + calendario.get(Calendar.MINUTE)
                + ")  ha enviado un archivo");
        tmp.getMensajes().setCaretPosition(tmp.getMensajes().getDocument().getLength());
    }

}
