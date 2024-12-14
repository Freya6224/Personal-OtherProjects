import javax.swing.*;
import java.awt.event.*;
import java.*;

public class MainFrameJava extends JDialog
{
    public static void main(String[] args)
    {
        MainFrameJava dialog=new MainFrameJava();
        dialog.pack();
        dialog.setVisible(true);
        System.exit(0);
    }

    private JPanel contentPane;
    private JPanel contentPane2;
    private JPanel JPanel2;
    private JPanel getPanel;
    private JButton buttonOK;
    private JButton buttonCancel;
    private JButton a5Button;
    private JButton a7Button;
    private JButton a8Button;
    private JButton a9Button;
    private JButton a11Button;
    private JButton a12Button;
    private JButton a13Button;
    private JButton a15Button;
    private JButton a16Button;
    private JTextField typeTextField1;
    private JTextField typeTextField;
    private JTextField enterXOTextField;
    private JTextField enterXOTextField1;
    private JButton a14Button;
    private JButton a10Button;
    private JButton a6Button;
    private JButton a1Button;
    private JButton a4Button;
    private JButton a3Button;
    private JButton a2Button;
    private Board gameBoard;


     //List<ArrayList<JButton>> buttons = new ArrayList<>();

    // Task:

    // 1. Make all 16 variables into array of J button.

    //watch Telusko video for action listener
    //first watch videos of the gui and take notes

    public MainFrameJava()
    {
//        ButtonsList.add(0,a1Button);
//        ButtonsList.add(1,a2Button);

         gameBoard = new Board();
        //gameBoard.createBoard();
        gameBoard.displayBoard();

        Player player1 = new Player();
        Player player2= new Player();

        Game game1 = new Game(gameBoard,player1,player2);
        //game1.setPlayer1() ;

        boolean[] turn = {true};

        setTitle("WELCOME TO GAME");
        setContentPane(contentPane);
        setModal(true);


        getRootPane().setDefaultButton(buttonOK);

        buttonOK.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e) {
                onOK();
            }
        });

        buttonCancel.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e) {
                onCancel();
            }
        });

        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);

        addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e) {
                onCancel();
            }
        });

        // call onCancel()
        contentPane.registerKeyboardAction(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onCancel();
            }
        }, KeyStroke.getKeyStroke(KeyEvent.VK_ESCAPE, 0), JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT);

        // listens to the player's actions

        StartScreen start = new StartScreen();


    a5Button.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e)
        {
            check();
            if(turn[0] == true)
            {
                gameBoard.updateBoard(1,0,enterXOTextField.getText());
                a5Button.setText(enterXOTextField.getText());
                game1.checkWinner(1,0,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a5Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(1,0,enterXOTextField1.getText());
                game1.checkWinner(1,0,enterXOTextField1.getText());
                turn[0] = true;
            }
            a5Button.setEnabled(false);
            checkResults();
        }
    });

    a7Button.addActionListener(new ActionListener() {
        @Override

        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a7Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(1,2,enterXOTextField.getText());
                game1.checkWinner(1,2,enterXOTextField.getText());
                turn[0] = false;
                a7Button.setEnabled(false);
            }
            else if (turn[0] == false)
            {
                a7Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(1,2,enterXOTextField1.getText());
                game1.checkWinner(1,2,enterXOTextField1.getText());
                turn[0] = true;
                a7Button.setEnabled(false);
            }
            checkResults();
        }
    });

    a8Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a8Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(1,3,enterXOTextField.getText());
                game1.checkWinner(1,3,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a8Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(1,3,enterXOTextField1.getText());
                game1.checkWinner(1,3,enterXOTextField1.getText());
                turn[0] = true;
            }
            a8Button.setEnabled(false);
            checkResults();
        }
    });

    a9Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a9Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(2,0,enterXOTextField.getText());
                game1.checkWinner(2,0,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a9Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(2,0,enterXOTextField1.getText());
                game1.checkWinner(2,0,enterXOTextField1.getText());
                turn[0] = true;
            }
            a9Button.setEnabled(false);
            checkResults();
            //checkOtherD();
        }
    });

    a11Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a11Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(2,2,enterXOTextField.getText());
                game1.checkWinner(2,2,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a11Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(2,2,enterXOTextField1.getText());
                game1.checkWinner(2,2,enterXOTextField1.getText());
                turn[0] = true;
            }
            a11Button.setEnabled(false);
            checkResults();
            //checkOtherD();
        }
    });

    a12Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a12Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(2,3,enterXOTextField.getText());
                game1.checkWinner(2,3,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a12Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(2,3,enterXOTextField1.getText());
                game1.checkWinner(2,3,enterXOTextField1.getText());
                turn[0] = true;
            }
            a12Button.setEnabled(false);
            checkResults();
        }
    });

    a13Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a13Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(3,0,enterXOTextField.getText());
                game1.checkWinner(3,0,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a13Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(3,0,enterXOTextField1.getText());
                game1.checkWinner(3,0,enterXOTextField1.getText());
                turn[0] = true;
            }
            a13Button.setEnabled(false);
            checkResults();
        }
    });

    a15Button.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a15Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(3,2,enterXOTextField.getText());
                game1.checkWinner(3,2,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a15Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(3,2,enterXOTextField1.getText());
                game1.checkWinner(3,2,enterXOTextField1.getText());
                turn[0] = true;
            }
            a15Button.setEnabled(false);
            checkResults();
        }
    });

    a16Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a16Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(3,3,enterXOTextField.getText());
                game1.checkWinner(3,3,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a16Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(3,3,enterXOTextField1.getText());
                game1.checkWinner(3,3,enterXOTextField1.getText());
                turn[0] = true;
            }
            a16Button.setEnabled(false);
            checkResults();
        }


    });

    a1Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            check();

            if(turn[0] == true)
            {
                a1Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(0,0,enterXOTextField.getText());
                game1.checkWinner(0,0,enterXOTextField.getText());
                turn[0] = false;

            }
            else if (turn[0] == false)
            {
                a1Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(0,0,enterXOTextField1.getText());
                game1.checkWinner(0,0,enterXOTextField1.getText());
                turn[0] = true;
            }
            a1Button.setEnabled(false);
            checkResults();

        }
    });

    a2Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a2Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(0,1,enterXOTextField.getText());
                game1.checkWinner(0,1,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a2Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(0,1,enterXOTextField1.getText());
                game1.checkWinner(0,1,enterXOTextField1.getText());
                turn[0] = true;
            }
            a2Button.setEnabled(false);
            checkResults();
        }
    });

    a3Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
           // check();
            if(turn[0] == true)
            {
                a3Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(0,2,enterXOTextField.getText());
                game1.checkWinner(0,2,enterXOTextField.getText());
                turn[0] = false;

            }
            else if (turn[0] == false)
            {
                a3Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(0,2,enterXOTextField1.getText());
                turn[0] = true;
                game1.checkWinner(0,2,enterXOTextField1.getText());
            }
            a3Button.setEnabled(false);
            checkResults();
        }
    });

    a4Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            //check();
            if(turn[0] == true)
            {
                a4Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(0,3,enterXOTextField.getText());
                game1.checkWinner(0,3,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a4Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(0,3,enterXOTextField1.getText());
                game1.checkWinner(0,3,enterXOTextField1.getText());
                turn[0] = true;
            }
            a4Button.setEnabled(false);
            checkResults();
        }
    });

    a6Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            //check();
            if(turn[0] == true)
            {
                a6Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(1,1,enterXOTextField.getText());
                game1.checkWinner(1,1,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a6Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(1,1,enterXOTextField1.getText());
                game1.checkWinner(1,1,enterXOTextField1.getText());
                turn[0] = true;
            }
            a6Button.setEnabled(false);
            checkResults();

        }
    });

    a10Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a10Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(2,1,enterXOTextField.getText());
                game1.checkWinner(2,1,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a10Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(2,1,enterXOTextField1.getText());
                game1.checkWinner(2,1,enterXOTextField1.getText());
                turn[0] = true;
            }
            a10Button.setEnabled(false);
            checkResults();

        }
    });

    a14Button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            check();
            if(turn[0] == true)
            {
                a14Button.setText(enterXOTextField.getText());
                gameBoard.updateBoard(3,1,enterXOTextField.getText());
                game1.checkWinner(3,1,enterXOTextField.getText());
                turn[0] = false;
            }
            else if (turn[0] == false)
            {
                a14Button.setText(enterXOTextField1.getText());
                gameBoard.updateBoard(3,1,enterXOTextField1.getText());
                game1.checkWinner(3,1,enterXOTextField1.getText());
                turn[0] = true;
            }
            a14Button.setEnabled(false);
            checkResults();

        }
    });


    }

    private void check()
    {
        if((enterXOTextField.getText().equals("X") && enterXOTextField1.getText().equals("O")) || (enterXOTextField.getText().equals("O")
                && enterXOTextField1.getText().equals("X")))
        {
            //get the buttons work
            a1Button.setEnabled(true);
            a2Button.setEnabled(true);
            a3Button.setEnabled(true);
            a4Button.setEnabled(true);
            a5Button.setEnabled(true);
            a6Button.setEnabled(true);
            a7Button.setEnabled(true);
            a8Button.setEnabled(true);
            a9Button.setEnabled(true);
            a10Button.setEnabled(true);
            a11Button.setEnabled(true);
            a12Button.setEnabled(true);
            a13Button.setEnabled(true);
            a14Button.setEnabled(true);
            a15Button.setEnabled(true);
            a16Button.setEnabled(true);

        }

        else
        {
            a1Button.setEnabled(false);
            a2Button.setEnabled(false);
            a3Button.setEnabled(false);
            a4Button.setEnabled(false);
            a5Button.setEnabled(false);
            a6Button.setEnabled(false);
            a7Button.setEnabled(false);
            a8Button.setEnabled(false);
            a9Button.setEnabled(false);
            a10Button.setEnabled(false);
            a11Button.setEnabled(false);
            a12Button.setEnabled(false);
            a13Button.setEnabled(false);
            a14Button.setEnabled(false);
            a15Button.setEnabled(false);
            a16Button.setEnabled(false);
            JOptionPane.showMessageDialog(this, "Check your inputs (Make sure that there are no space)", "CHECK", JOptionPane.ERROR_MESSAGE );

        }
    }

    public void computerActions()
    {

    }

    private void onOK()
    {
        dispose();
    }

    private void onCancel()
    {
        dispose();
    }

    // tried making the array for the winning pack, but it didn't work
    // this is a method to check the results - checks if there is a winner after every move
    // using if else statements ------ find if it is possible with the loops or any other ways


    public void checkResults() {
        // add winning actions for all the buttons
/*
    public void computerVersion()
    {
        //check for computer version part

        EndScreenJava show = new EndScreenJava();
        System.exit(0);
        show.setVisible(true);

        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);

        addWindowListener(new WindowAdapter()
        {
            public void windowOpen(WindowEvent e) {
                computerVersion();
            }
        });

        MainFrameJava hide = new MainFrameJava();
        hide.setVisible(false);
    }

 */
    }


    public static class SecondFormat extends MainFrameJava
    {
         public static void main(String[] args)
         {
             MainFrameJava dialog=new MainFrameJava();
             dialog.pack();
             dialog.setVisible(true);
             System.exit(0);
         }



    }
}



