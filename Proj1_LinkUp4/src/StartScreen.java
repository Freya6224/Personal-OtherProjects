import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class StartScreen extends JDialog
{

    private JButton player;
    private JPanel panel1;
    private JButton computer;
    private JTextField Name1;
    private JTextField Name2;
    public  JTextField input1;
    public  JTextField input2;
    private JLabel Label1;
    private JLabel Label2;

    public List<ArrayList<JPanel>> inputs;

    public static void main(String[] args) {

        StartScreen dialog1 = new StartScreen();
        dialog1.pack();
        dialog1.setVisible(true);
        System.exit(0);


    }


    public StartScreen() {

        setTitle("WELCOME TO THE GAME");
        setContentPane(panel1);
        setModal(true);

        Label1.setVisible(false);
        Label2.setVisible(false);
        Name1.setVisible(false);
        Name2.setVisible(false);
        input1.setVisible(false);
        input2.setVisible(false);


        computer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Computer openComputer = new Computer();
                openComputer.setSize(350,400);
                openComputer.setVisible(true);
            }
        });

        player.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                MainFrameJava open = new MainFrameJava();
                open.setSize(350,400);
                open.setVisible(true);
            }
        });


    }

}

