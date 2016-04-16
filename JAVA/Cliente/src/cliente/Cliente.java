package cliente;

import P2P.cs;
import P2P.csHelper;
import java.util.*;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Cliente {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        org.omg.CORBA.ORB orb = org.omg.CORBA.ORB.init(args, null);
        if (orb == null) {
            System.exit(-1);
        }
        try {
            // obtain service from naming server
            org.omg.CORBA.Object ns_obj = orb.resolve_initial_references("NameService");
            org.omg.CosNaming.NamingContext nc = org.omg.CosNaming.NamingContextHelper.narrow(ns_obj);
            org.omg.CosNaming.NameComponent[] path = {new org.omg.CosNaming.NameComponent("Server", "")};
            org.omg.CORBA.Object obj = nc.resolve(path);
            cs clienteServidor = csHelper.narrow(obj);

            PanelLogueo p = new PanelLogueo(clienteServidor, orb);
            p.setVisible(true);

            
        } catch (org.omg.CORBA.ORBPackage.InvalidName exception) {
            exception.printStackTrace(System.out);
        } catch (org.omg.CosNaming.NamingContextPackage.NotFound exception) {
            exception.printStackTrace(System.out);
        } catch (org.omg.CosNaming.NamingContextPackage.CannotProceed exception) {
            exception.printStackTrace(System.out);
        } catch (org.omg.CosNaming.NamingContextPackage.InvalidName exception) {
            exception.printStackTrace(System.out);
        } catch (org.omg.CORBA.COMM_FAILURE exception) {
            exception.printStackTrace(System.out);
        } catch (Exception exception) {
            exception.printStackTrace(System.out);
        }

    }
}
