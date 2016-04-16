package cliente;

import P2P.cs;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextField;

public class AnadirAmigo extends javax.swing.JFrame {

    private cs server;
    private String correo;
    private String nombreOcorreo;

    /**
     * Creates new form AnadirAmigo
     */
    public AnadirAmigo(cs serv, String mail) {
        initComponents();
        server = serv;
        correo = mail;
        nombreOcorreo = "";
    }

    public AnadirAmigo() {
        initComponents();
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

    public JButton getAgregarAmigo() {
        return agregarAmigo;
    }

    public void setAgregarAmigo(JButton agregarAmigo) {
        this.agregarAmigo = agregarAmigo;
    }

    public JButton getBuscarAmigo() {
        return buscarAmigo;
    }

    public void setBuscarAmigo(JButton buscarAmigo) {
        this.buscarAmigo = buscarAmigo;
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

    public JList getCorreosBuscados() {
        return correosBuscados;
    }

    public void setCorreosBuscados(JList correosBuscados) {
        this.correosBuscados = correosBuscados;
    }

    public JScrollPane getjScrollPane1() {
        return jScrollPane1;
    }

    public void setjScrollPane1(JScrollPane jScrollPane1) {
        this.jScrollPane1 = jScrollPane1;
    }

    public JTextField getNombreOrCorreo() {
        return nombreOrCorreo;
    }

    public void setNombreOrCorreo(JTextField nombreOrCorreo) {
        this.nombreOrCorreo = nombreOrCorreo;
    }

    public String getNombreOCorreo() {
        return nombreOcorreo;
    }

    public void setNombreOCorreo(String name) {
        this.nombreOcorreo = name;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        nombreOrCorreo = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        correosBuscados = new javax.swing.JList();
        agregarAmigo = new javax.swing.JButton();
        buscarAmigo = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Helvetica", 1, 13)); // NOI18N
        jLabel1.setText("A�adir amigos");

        nombreOrCorreo.setFont(new java.awt.Font("Helvetica", 0, 13)); // NOI18N

        jLabel2.setFont(new java.awt.Font("Helvetica", 0, 13)); // NOI18N
        jLabel2.setText("Nombre o correo:");

        correosBuscados.setFont(new java.awt.Font("Helvetica", 0, 13)); // NOI18N
        jScrollPane1.setViewportView(correosBuscados);

        agregarAmigo.setFont(new java.awt.Font("Helvetica", 0, 13)); // NOI18N
        agregarAmigo.setText("Agregar amigo");
        agregarAmigo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                agregarAmigoActionPerformed(evt);
            }
        });

        buscarAmigo.setText("Buscar amigo");
        buscarAmigo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarAmigoActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(256, 256, 256)
                        .addComponent(jLabel1))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(35, 35, 35)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 579, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel2)
                                .addGap(38, 38, 38)
                                .addComponent(nombreOrCorreo, javax.swing.GroupLayout.PREFERRED_SIZE, 395, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(155, 155, 155)
                        .addComponent(buscarAmigo)
                        .addGap(83, 83, 83)
                        .addComponent(agregarAmigo)))
                .addContainerGap(36, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(23, 23, 23)
                .addComponent(jLabel1)
                .addGap(36, 36, 36)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(nombreOrCorreo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2))
                .addGap(39, 39, 39)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(65, 65, 65)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(agregarAmigo)
                    .addComponent(buscarAmigo))
                .addContainerGap(75, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void agregarAmigoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_agregarAmigoActionPerformed
        Pattern p = Pattern.compile("^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@"
                + "[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$");

        Matcher m = null;

        if (this.getNombreOrCorreo() != null) {
            m = p.matcher(this.getNombreOrCorreo().getText());
        }

        if (this.getCorreosBuscados().getSelectedValue() != null) {
            String correoaux = this.getCorreosBuscados().getSelectedValue().toString();
            if (server.pedirAmistad(this.getCorreo(), correoaux)) {
                JOptionPane.showMessageDialog(this,
                        "Petici�n de amistad enviada correctamente a " + correoaux);
            } else {
                JOptionPane.showMessageDialog(this,
                        "No se puede realizar la petici�n de amistad");
            }
        } else if (m != null && m.matches()) {
            if (server.pedirAmistad(this.getCorreo(), this.getNombreOrCorreo().getText())) {
                JOptionPane.showMessageDialog(this,
                        "Petici�n de amistad enviada correctamente a " + this.getNombreOrCorreo().getText());
            } else {
                JOptionPane.showMessageDialog(this,
                        "No se puede realizar la petici�n de amistad");
            }
        } else {
            JOptionPane.showMessageDialog(this,
                    "Error");
        }

    }//GEN-LAST:event_agregarAmigoActionPerformed

    private void buscarAmigoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buscarAmigoActionPerformed
        Pattern p = Pattern.compile("^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@"
                + "[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$");

        Matcher m = null;

        if (this.getNombreOrCorreo() != null) {
            m = p.matcher(this.getNombreOrCorreo().getText());
        }
        if (this.getNombreOrCorreo().getText().length() > 2) {
            if (m != null && !m.matches()) { // Si no coincide significa que no es un correo, por lo tanto es un nombre
                String correosBuscados[] = server.buscaAmigos(this.getNombreOrCorreo().getText(), this.getCorreo());
                if (correosBuscados[0].equals("fallo@fallo.com")) {   // PUEDE CAMBIAR
                    JOptionPane.showMessageDialog(this,
                            "No existe ning�n contacto con ese nombre");
                } else {
                    this.getCorreosBuscados().setListData(correosBuscados);
                }
            } else {    // Es un correo
                JOptionPane.showMessageDialog(this,
                        "Si sabe la direcci�n de correo electr�nico de su contacto, puede a�adirlo como amigo directamente");
            }
        } else {
            JOptionPane.showMessageDialog(this,
                    "Introduzca un nombre v�lido");
        }
    }//GEN-LAST:event_buscarAmigoActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.dispose();
    }//GEN-LAST:event_formWindowClosing

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
            java.util.logging.Logger.getLogger(AnadirAmigo.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(AnadirAmigo.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(AnadirAmigo.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(AnadirAmigo.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new AnadirAmigo().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton agregarAmigo;
    private javax.swing.JButton buscarAmigo;
    private javax.swing.JList correosBuscados;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextField nombreOrCorreo;
    // End of variables declaration//GEN-END:variables
}
