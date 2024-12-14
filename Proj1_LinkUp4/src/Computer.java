import javax.swing.*;
import java.awt.event.*;
import java.*;

public class Computer extends JDialog
{

    public static void main(String[] args)
    {
        Computer dialog=new Computer();
        dialog.pack();
        dialog.setVisible(true);
        System.exit(0);
    }

    private JTextField letter2;
    private JButton button1;
    private JButton button2;
    private JButton button3;
    private JButton button4;
    private JButton button5;
    private JButton button6;
    private JButton button7;
    private JButton button8;
    private JButton button9;
    private JButton button10;
    private JButton button11;
    private JButton button12;
    private JButton button13;
    private JButton button14;
    private JButton button15;
    private JButton button16;
    private JLabel playerMove;
    private JLabel computer;
    private JTextField letter;
    private JButton OK;


    JButton getButton1, getButton2, getButton3, getButton4, getButton5, getButton6, getButton7, getButton8,
    getButton9, getButton10, getButton11, getButton12,getButton13, getButton14, getButton15,getButton16;

    private  JButton buttons1[];

    private int buttonCount = 16;

     public void randomButtons()
     {
         for (int i = 0; i < buttonCount; i++)
         {
             buttons1[i].addActionListener((ActionListener) this);

         }

     }

     //other solution to make the buttons randomize
    // create a number list so that it can create random number
    //Then assign a number to a button so that it can randomly pick a button

    public Computer()
    {

        setTitle("WELCOME TO GAME");
        setContentPane(getContentPane());
        setModal(true);

        getRootPane().setDefaultButton(OK);

        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                randomButtons();
            
            }
        });
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {


            }
        });

        button3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button5.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button6.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button7.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button8.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button9.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button10.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button11.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button12.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button13.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button14.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button15.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button15.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        button16.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });

        OK.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });
    }



}



