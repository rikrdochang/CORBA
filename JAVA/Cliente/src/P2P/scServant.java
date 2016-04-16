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
        p.getPeticionesAmistadPendientes().add(correo);
    }

    @Override
    public void notificar(String correo, boolean estado) {
        /* Qu� pasa si alg�n amigo se desconecta pero tengo un chat abierto con el? Al desloguearse deber�a destruir su chat y
         poner mi chat a setVisible(false), para forzar que se refresque la lista de amigos y as� no me deje entrar al intentar dar en bot�n Chatear    */
        int tam = 0, tamViejo = 0, tmp = 0;
        amigo[] amigosAux;
        amigo[] amigos = p.getFriends();

        for (amigo a : amigos) {
            if (a.correo.equals(correo)) {
                a.estado = estado;
                tam++;
            }
        }
        if (tam == 0) {
            tamViejo = p.getFriends().length;
            amigosAux = new amigo[tamViejo + 1];
            for (amigo a : amigos) {
                amigosAux[tmp] = a;
                tmp++;
            }
            amigosAux[tmp + 1] = amigosAux[tmp];
            amigosAux[tmp] = new amigo(correo, estado);
            p.setFriends(amigosAux);
        }
        p.refreshAmigos();

    }

}
