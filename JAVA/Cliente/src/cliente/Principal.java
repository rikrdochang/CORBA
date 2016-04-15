package cliente;

import P2P.amigo;
import P2P.cc;
import P2P.ccHelper;
import P2P.cs;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import org.omg.CORBA.ORB;
import org.omg.CORBA.ORBPackage.InvalidName;
import org.omg.CosNaming.NamingContext;
import org.omg.CosNaming.NamingContextPackage.CannotProceed;
import org.omg.CosNaming.NamingContextPackage.NotFound;

public class Principal extends javax.swing.JFrame {

    private cs server;
    private String correo;
    private org.omg.CORBA.ORB orb;
    private org.omg.CosNaming.NamingContext nc;
    private ArrayList<Chat> ventanasAbiertas;
    private amigo[] friends;

    public Principal(cs serv, String mail, org.omg.CORBA.ORB orb2, amigo[] amig) {
        try {
            initComponents();
            orb = orb2;
            org.omg.CORBA.Object ns_obj = orb.resolve_initial_references("NameService");
            nc = org.omg.CosNaming.NamingContextHelper.narrow(ns_obj);
            server = serv;
            correo = mail;
            ventanasAbiertas = new ArrayList<>();
            if (amig != null) {
                friends = amig;
                int tam = amigos.getSize().width;
                String[] lista = new String[tam];
                for (int i = 0; i < tam; i++) {
                    if (amig[tam].estado) {
                        lista[tam] = amig[tam].correo + " " + "CONECTADO";
                    } else {
                        lista[tam] = amig[tam].correo;
                    }
                }
                this.getAmigos().setListData(lista);
            }
        } catch (InvalidName ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public Principal() {
        initComponents();
    }

    public amigo[] getFriends() {
        return friends;
    }

    public void setFriends(amigo[] friends) {
        this.friends = friends;
    }

    public ORB getOrb() {
        return orb;
    }

    public void setOrb(ORB orb) {
        this.orb = orb;
    }

    public NamingContext getNc() {
        return nc;
    }

    public void setNc(NamingContext nc) {
        this.nc = nc;
    }

    public ArrayList<Chat> getVentanasAbiertas() {
        return ventanasAbiertas;
    }

    public void setVentanasAbiertas(ArrayList<Chat> ventanasAbiertas) {
        this.ventanasAbiertas = ventanasAbiertas;
    }

    public JButton getChatear() {
        return chatear;
    }

    public void setChatear(JButton chatear) {
        this.chatear = chatear;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public cs getServer() {
        return server;
    }

    public void setServer(cs server) {
        this.server = server;
    }

    public JList getAmigos() {
        return amigos;
    }

    public void setAmigos(JList amigos) {
        this.amigos = amigos;
    }

    public JButton getAnadirAmigos() {
        return anadirAmigos;
    }

    public void setAnadirAmigos(JButton anadirAmigos) {
        this.anadirAmigos = anadirAmigos;
    }

    public JMenuItem getBorrarCuenta() {
        return borrarCuenta;
    }

    public void setBorrarCuenta(JMenuItem borrarCuenta) {
        this.borrarCuenta = borrarCuenta;
    }

    public JMenuItem getCambiarContrasena() {
        return cambiarContrasena;
    }

    public void setCambiarContrasena(JMenuItem cambiarContrasena) {
        this.cambiarContrasena = cambiarContrasena;
    }

    public JButton getCerrarSesion() {
        return cerrarSesion;
    }

    public void setCerrarSesion(JButton cerrarSesion) {
        this.cerrarSesion = cerrarSesion;
    }

    public JLabel getjLabel1() {
        return jLabel1;
    }

    public void setjLabel1(JLabel jLabel1) {
        this.jLabel1 = jLabel1;
    }

    public JLabel getjLabel2() {
        return jLabel2;
    }

    public void setjLabel2(JLabel jLabel2) {
        this.jLabel2 = jLabel2;
    }

    public JMenuBar getjMenuBar1() {
        return jMenuBar1;
    }

    public void setjMenuBar1(JMenuBar jMenuBar1) {
        this.jMenuBar1 = jMenuBar1;
    }

    public JMenuItem getjMenuItem1() {
        return jMenuItem1;
    }

    public void setjMenuItem1(JMenuItem jMenuItem1) {
        this.jMenuItem1 = jMenuItem1;
    }

    public JScrollPane getjScrollPane2() {
        return jScrollPane2;
    }

    public void setjScrollPane2(JScrollPane jScrollPane2) {
        this.jScrollPane2 = jScrollPane2;
    }

    public JMenu getOpciones() {
        return opciones;
    }

    public void setOpciones(JMenu opciones) {
        this.opciones = opciones;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jMenuItem1 = new javax.swing.JMenuItem();
        jLabel1 = new javax.swing.JLabel();
        jScrollPane2 = new javax.swing.JScrollPane();
        amigos = new javax.swing.JList();
        jLabel2 = new javax.swing.JLabel();
        cerrarSesion = new javax.swing.JButton();
        anadirAmigos = new javax.swing.JButton();
        chatear = new javax.swing.JButton();
        jMenuBar1 = new javax.swing.JMenuBar();
        opciones = new javax.swing.JMenu();
        borrarCuenta = new javax.swing.JMenuItem();
        cambiarContrasena = new javax.swing.JMenuItem();

        jMenuItem1.setText("jMenuItem1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("Usuario");

        amigos.setModel(new javax.swing.AbstractListModel() {
            String[] strings = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5" };
            public int getSize() { return strings.length; }
            public Object getElementAt(int i) { return strings[i]; }
        });
        amigos.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        jScrollPane2.setViewportView(amigos);

        jLabel2.setText("Lista de amigos");

        cerrarSesion.setText("Cerrar sesion");
        cerrarSesion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cerrarSesionActionPerformed(evt);
            }
        });

        anadirAmigos.setText("Anadir amigos");
        anadirAmigos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                anadirAmigosActionPerformed(evt);
            }
        });

        chatear.setText("Chatear");
        chatear.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                chatearActionPerformed(evt);
            }
        });

        opciones.setText("Opciones");

        borrarCuenta.setText("Borrar cuenta");
        borrarCuenta.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                borrarCuentaActionPerformed(evt);
            }
        });
        opciones.add(borrarCuenta);

        cambiarContrasena.setText("Cambiar contrasena");
        cambiarContrasena.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cambiarContrasenaActionPerformed(evt);
            }
        });
        opciones.add(cambiarContrasena);

        jMenuBar1.add(opciones);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(19, 19, 19)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel2)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addGap(0, 0, Short.MAX_VALUE)
                                .addComponent(jLabel1)
                                .addGap(222, 222, 222)))
                        .addComponent(cerrarSesion))
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 707, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(24, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addGap(65, 65, 65)
                .addComponent(anadirAmigos)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(chatear)
                .addGap(89, 89, 89))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGap(19, 19, 19)
                        .addComponent(jLabel2)
                        .addGap(5, 5, 5))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(cerrarSesion)
                        .addGap(18, 18, 18)))
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 446, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(anadirAmigos)
                    .addComponent(chatear))
                .addContainerGap(23, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void borrarCuentaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_borrarCuentaActionPerformed
        // TODO add your handling code here:
        if (server.desregistro(this.getCorreo())) {
            JOptionPane.showMessageDialog(this,
                    "Cuenta eliminada correctamente");
            PanelLogueo pl = new PanelLogueo(server, orb);
            this.setVisible(false);
            pl.setVisible(true);
            this.dispose();
        } else {
            JOptionPane.showMessageDialog(this,
                    "Fallo al intentar eliminar la cuenta");
        }
    }//GEN-LAST:event_borrarCuentaActionPerformed

    private void cerrarSesionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cerrarSesionActionPerformed
        if (server.deslogueo(this.getCorreo())) {
            PanelLogueo pl = new PanelLogueo(server, orb);
            this.setVisible(false);
            pl.setVisible(true);
            this.dispose();
        } else {
            JOptionPane.showMessageDialog(this,
                    "Fallo al intentar cerrar sesión");
        }
    }//GEN-LAST:event_cerrarSesionActionPerformed

    private void anadirAmigosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_anadirAmigosActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_anadirAmigosActionPerformed

    private void chatearActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_chatearActionPerformed
        if (amigos.getSelectedValue() != null) {
            try {
                System.out.println((amigos.getSelectedValue().toString()));
                System.out.println(amigos.getSelectedIndex());
                String correoAmigo = amigos.getSelectedValue().toString().split(" ")[0];
                Chat ventana = ventanasAbiertas.get(amigos.getSelectedIndex());
                if (ventana == null) {
                    org.omg.CosNaming.NameComponent[] path = {new org.omg.CosNaming.NameComponent(correoAmigo + "cc", "")};
                    org.omg.CORBA.Object obj = nc.resolve(path);
                    cc cliente = ccHelper.narrow(obj);

                    ventana = new Chat(cliente, correo);
                    ventana.setVisible(true);
                } else {
                    ventana.setVisible(true);
                }

            } catch (NotFound ex) {
                Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
            } catch (CannotProceed ex) {
                Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
            } catch (org.omg.CosNaming.NamingContextPackage.InvalidName ex) {
                Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
    }//GEN-LAST:event_chatearActionPerformed

    private void cambiarContrasenaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cambiarContrasenaActionPerformed
        CambiarContrasena cc = new CambiarContrasena(server, correo);
        cc.setVisible(true);
    }//GEN-LAST:event_cambiarContrasenaActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Principal().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JList amigos;
    private javax.swing.JButton anadirAmigos;
    private javax.swing.JMenuItem borrarCuenta;
    private javax.swing.JMenuItem cambiarContrasena;
    private javax.swing.JButton cerrarSesion;
    private javax.swing.JButton chatear;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JMenu opciones;
    // End of variables declaration//GEN-END:variables
}
