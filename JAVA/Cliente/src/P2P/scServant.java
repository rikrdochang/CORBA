package P2P;

import cliente.Principal;
import javax.swing.JOptionPane;

/**
 *
 * @author brunis46
 */
public class scServant extends scPOA {

    private Principal p;

    public scServant(Principal p) {
        this.p = p;
    }

    @Override
    public void sendAmistad(String correo) {
        String pregunta = correo + " le ha enviado una solicitud de amistad, �desea aceptarla?";
        int op = JOptionPane.showConfirmDialog(p, pregunta, "�Nueva petici�n de amistad!", JOptionPane.OK_CANCEL_OPTION);
        if (op == 1) {
            if (p.getServer().aceptarAmistad(p.getCorreo(), correo)) {
                JOptionPane.showMessageDialog(p,
                        "Solicitud de amistad aceptada con �xito");
            } else {
                JOptionPane.showMessageDialog(p,
                        "Ha ocurrido un error al aceptar la solicitud de amistad");
            }
        } else {
            // Acci�n en server para denegar la solicitud de amistad
        }
    }

    @Override
    public void notificar(String correo, boolean estado) {  
/* Qu� pasa si alg�n amigo se desconecta pero tengo un chat abierto con el? Al desloguearse deber�a destruir su chat y
        poner mi chat a setVisible(false), para forzar que se refresque la lista de amigos y as� no me deje entrar al intentar dar en bot�n Chatear    */
        for (amigo a : p.getFriends()) {
            if (a.correo.equals(correo)) {
                a.estado = estado;
            }
        }
        p.refreshAmigos();

    }

}
