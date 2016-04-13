package cliente;

import java.rmi.RemoteException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Cliente {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        PanelLogueo p = new PanelLogueo();
        p.setVisible(true);
        
        
         Thread t = new Thread(new Runnable() {
            public void run() {
                    // ESPERA POR NUEVOS MENSAJES Y CREA VENTANAS SI NO ESTÁN CREADAS PARA DICHOS MENSAJES
            }
        });

        t.start();
        
        Thread x = new Thread(new Runnable() {
            public void run() {
                    // PETICIONES DE AMISTAD
            }
        });

        x.start();
        
        
        
        
    }
    
}
