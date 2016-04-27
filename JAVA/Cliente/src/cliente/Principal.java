package cliente;

import P2P.amigo;
import P2P.cc;
import P2P.cs;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JButton;
import javax.swing.JFrame;
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

public class Principal extends javax.swing.JFrame {

    private cs server;
    private cc yo;
    private String correo;
    private org.omg.CORBA.ORB orb;
    private org.omg.CosNaming.NamingContext nc;
    private amigo[] friends;
    private ArrayList<String> peticionesAmistadPendientes;
    private HashMap<String, Chat> chatsAmigos;

    public Principal(cs serv, String mail, org.omg.CORBA.ORB orb2, amigo[] amig) {
        try {
            initComponents();
            orb = orb2;
            org.omg.CORBA.Object ns_obj = orb.resolve_initial_references("NameService");
            nc = org.omg.CosNaming.NamingContextHelper.narrow(ns_obj);
            server = serv;
            correo = mail;
            peticionesAmistadPendientes = new ArrayList<>();
            chatsAmigos = new HashMap<>();

            if (amig != null) {
                friends = amig;
                int tam = 0;
                String[] lista;
                while (!amig[tam].correo.equals("ready@ready.com")) {
                    tam++;
                }
                lista = new String[tam];
                for (int i = 0; i < tam; i++) {
                    if (amig[i].estado) {
                        lista[i] = amig[i].correo + "   \t" + "CONECTADO";
                    } else {
                        lista[i] = amig[i].correo;
                    }
                }
                this.getAmigos().setListData(lista);
            } else {
                friends = new amigo[1];
                friends[0] = new amigo("ready@ready.com", false);
                this.getAmigos().setListData(new String[1]);
            }
        } catch (InvalidName ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        }
        this.getUser().setText(correo);
    }

    public Principal() {
        initComponents();
    }

    public void refreshAmigos() {
        if (friends != null) {
            int tam = 0;
            String[] lista;

            while (!friends[tam].correo.equals("ready@ready.com")) {
                tam++;
            }
            lista = new String[tam];
            for (int i = 0; i < tam; i++) {
                if (friends[i].estado) {
                    lista[i] = friends[i].correo + "   \t" + "CONECTADO";
                } else {
                    lista[i] = friends[i].correo;
                    if (chatsAmigos.get(lista[i]) != null) {
                        chatsAmigos.get(lista[i]).dispose();
                        chatsAmigos.remove(lista[i]);
                    }
                }
            }
            this.getAmigos().setListData(lista);
        }
    }

    public void recibirPeticionesAmistad() {
        this.getServer().initAmistad(this.getCorreo());
    }

    public HashMap<String, Chat> getChatsAmigos() {
        return chatsAmigos;
    }

    public void setChatsAmigos(HashMap<String, Chat> chatsAmigos) {
        this.chatsAmigos = chatsAmigos;
    }

    public JMenuItem getPeticionesPendientes() {
        return peticionesPendientes;
    }

    public void setPeticionesPendientes(JMenuItem peticionesPendientes) {
        this.peticionesPendientes = peticionesPendientes;
    }

    public ArrayList<String> getPeticionesAmistadPendientes() {
        return peticionesAmistadPendientes;
    }

    public void setPeticionesAmistadPendientes(ArrayList<String> peticionesAmistadPendientes) {
        this.peticionesAmistadPendientes = peticionesAmistadPendientes;
    }

    public cc getYo() {
        return yo;
    }

    public void setYo(cc yo) {
        this.yo = yo;
    }

    public JLabel getUser() {
        return user;
    }

    public void setUser(JLabel user) {
        this.user = user;
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
        return user;
    }

    public void setjLabel1(JLabel jLabel1) {
        this.user = jLabel1;
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
        user = new javax.swing.JLabel();
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
        peticionesPendientes = new javax.swing.JMenuItem();

        jMenuItem1.setText("jMenuItem1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });

        user.setFont(new java.awt.Font("Helvetica", 1, 14)); // NOI18N
        user.setText("Usuario");

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

        peticionesPendientes.setText("Peticiones de amistad pendientes");
        peticionesPendientes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                peticionesPendientesActionPerformed(evt);
            }
        });
        opciones.add(peticionesPendientes);

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
                                .addComponent(user)
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
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(40, 40, 40)
                        .addComponent(jLabel2)
                        .addGap(5, 5, 5))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(cerrarSesion)
                            .addComponent(user))
                        .addGap(18, 18, 18)))
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 446, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(anadirAmigos)
                    .addComponent(chatear))
                .addContainerGap(24, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void borrarCuentaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_borrarCuentaActionPerformed
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
            this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            PanelLogueo pl = new PanelLogueo(server, orb);
            int tam = 0;
            while (!friends[tam].correo.equals("ready@ready.com")) {
                if ((chatsAmigos.get(friends[tam].correo)) != null) {
                    chatsAmigos.get(friends[tam].correo).dispose();
                }
                tam++;
            }

            chatsAmigos.clear();
            this.setVisible(false);
            pl.setVisible(true);
            this.dispose();
        } else {
            JOptionPane.showMessageDialog(this,
                    "Fallo al intentar cerrar sesión");
        }
    }//GEN-LAST:event_cerrarSesionActionPerformed

    private void anadirAmigosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_anadirAmigosActionPerformed
        AnadirAmigo aa = new AnadirAmigo(server, correo);
        aa.setVisible(true);
    }//GEN-LAST:event_anadirAmigosActionPerformed

    private void chatearActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_chatearActionPerformed
        if (amigos.getSelectedValue() != null) {
            String correoEstado[] = amigos.getSelectedValue().toString().split("   \t");
            String correoAmigo = correoEstado[0];

            if (correoEstado.length == 1) {
                JOptionPane.showMessageDialog(this,
                        "El amigo con el que intenta hablar está desconectado");
            } else {
                yo.init(correoAmigo);
            }
        } else {
            JOptionPane.showMessageDialog(this,
                    "Seleccione un amigo con el que hablar");

        }
    }//GEN-LAST:event_chatearActionPerformed

    private void cambiarContrasenaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cambiarContrasenaActionPerformed
        CambiarContrasena cc = new CambiarContrasena(server, correo);
        cc.setVisible(true);
    }//GEN-LAST:event_cambiarContrasenaActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        if (server.deslogueo(this.getCorreo())) {
            PanelLogueo pl = new PanelLogueo(server, orb);
            this.setVisible(false);
            pl.setVisible(true);
            this.dispose();
        } else {
            JOptionPane.showMessageDialog(this,
                    "Fallo al intentar cerrar sesión");
        }
    }//GEN-LAST:event_formWindowClosing

    private void peticionesPendientesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_peticionesPendientesActionPerformed
        ArrayList<String> aux = new ArrayList<>();

        for (String c : peticionesAmistadPendientes) {
            String pregunta = c + " le ha enviado una solicitud de amistad, ¿desea aceptarla?";
            int op = JOptionPane.showConfirmDialog(this, pregunta, "¡ Petición de amistad de " + c + " !", JOptionPane.OK_CANCEL_OPTION);
            if (op == 0) {
                if (this.getServer().aceptarAmistad(this.getCorreo(), c)) {
                    JOptionPane.showMessageDialog(this,
                            "Solicitud de amistad aceptada con éxito");
                } else {
                    JOptionPane.showMessageDialog(this,
                            "Ha ocurrido un error al aceptar la solicitud de amistad");
                }
                aux.add(c);
            } else if (op == 2) {
                if (this.getServer().noAmistad(this.getCorreo(), c)) {
                    JOptionPane.showMessageDialog(this,
                            "Solicitud de amistad denegada");
                } else {
                    JOptionPane.showMessageDialog(this,
                            "Ha ocurrido un error al denegar la solicitud de amistad");
                }
                aux.add(c);
            }
        }
        for (String c : aux) {
            peticionesAmistadPendientes.remove(c);
        }
    }//GEN-LAST:event_peticionesPendientesActionPerformed

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
    private javax.swing.JLabel jLabel2;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JMenu opciones;
    private javax.swing.JMenuItem peticionesPendientes;
    private javax.swing.JLabel user;
    // End of variables declaration//GEN-END:variables
}
