/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package P2P;

import cliente.Chat;
import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 *
 * @author brunis46
 */
public class ccServant extends ccPOA{

    private Chat c;
    
    @Override
    public void talk(String mensaje) {
        Calendar calendario = new GregorianCalendar();
        c.getMensajes().setText(c.getMensajes().getText() + "\n" + c.getCorreo()+"("
                +calendario.get(Calendar.HOUR_OF_DAY)+
                ":"+calendario.get(Calendar.MINUTE)+
                "):      " +mensaje);
    }
    
}
