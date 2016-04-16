/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cliente;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 *
 * @author brunis46
 */
public class test {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String correo = "bruno@correo.com";
        String pregunta = correo + " le ha enviado una solicitud de amistad, ¿desea aceptarla?";
        JFrame j = new JFrame();
        j.setVisible(true);
        int op = 1;
        op = JOptionPane.showConfirmDialog(j, pregunta, "¡Nueva petición de amistad!", JOptionPane.OK_CANCEL_OPTION);
        System.out.println(op);
    }

}
