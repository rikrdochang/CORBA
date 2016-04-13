package P2P;

import cliente.Principal;

/**
 *
 * @author brunis46
 */
public class scServant extends scPOA{
    
    private Principal p;

    public scServant(Principal p) {
        this.p = p;
    }
    
    @Override
    public void sendAmistad(String correo) {
        
    }

    @Override
    public void notificar(String correo, boolean estado) {
        
    }
    
    
    
}
