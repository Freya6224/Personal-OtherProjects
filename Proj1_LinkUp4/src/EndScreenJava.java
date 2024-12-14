import javax.swing.*;

import java.awt.event.*;

public class EndScreenJava extends JDialog{
    private JButton restart;
    private JButton exit;
    private JLabel rLabel;

    //create the screen where play can start a new game and show the results

    //let player start the new game

    public EndScreenJava() {
        restart.addInputMethodListener(new InputMethodListener() {
            @Override
            public void inputMethodTextChanged(InputMethodEvent event) {
                //JOptionPane.showMessageDialog(this, "WIN", "Results", JOptionPane.INFORMATION_MESSAGE );

            }

            @Override
            public void caretPositionChanged(InputMethodEvent event) {

            }
        });
        restart.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });
    }
}
