import javax.swing.*;
import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.List;

public class Game
{
    private  Board virtualBoard;
    private Player player1;
    private Player player2;

    public Player getPlayer1() {
        return player1;
    }

    public void setPlayer1(Player player1) {
        this.player1 = player1;
    }

    public Player getPlayer2() {
        return player2;
    }

    public void setPlayer2(Player player2) {
        this.player2 = player2;
    }

    public Game(Board virtualBoard, Player player1, Player player2)
    {
        this.virtualBoard = virtualBoard;

        System.out.println("game Board: " + this.virtualBoard.getVirtualBoard());
        this.player1 = player1;
        this.player2 = player2;
    }

    @Override
    public String toString() {
        return "Game{" +
                "virtualBoard=" + virtualBoard +
                ", player1=" + player1 +
                ", player2=" + player2 +
                '}';
    }

    public void play()
     {
         // Entire Game logic.
         // Loop
         // makeMove(), validMove(), checkWin()
     }

     public void checkWinner(int row, int col, String val)
     {
       checkVertical(row,col);
       checkHorizontal(row,col);
       checkDiagonal(row,col);
     }

     public  boolean checkVertical(int row, int col)
     {
         if(row == 0)
         {
             checkDown2(row,col);
         }
         else if(row == 1)
         {
             checkDown2(row,col);
             checkUpDown(row,col);
         }
         else if(row == 2)
         {
             checkUpDown(row,col);
             checkUp2(row,col);
         }
         else if(row == 3)
         {
             checkUp2(row,col);
         }
         return false;
     }

    //check if it works
    //If it works then stop the game
    //then move on to computer vs computer format

    // AND if it doesn't then work try to finish it by this weekend

     public  void checkDown2(int row, int col)
     {
         System.out.println("In check condition: " + virtualBoard.getVirtualBoard().get(row).get(col)) ;
         if(virtualBoard.getVirtualBoard().get(row).get(col).equals(virtualBoard.getVirtualBoard().get(row+1).get(col)) &&
                 (virtualBoard.getVirtualBoard().get(row).get(col).equals(virtualBoard.getVirtualBoard().get(row+2).get(col))))
         {
             System.out.println("win down");
             JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);

         }
     }

     public  void checkUpDown(int row, int col)
     {
         if(((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row+1).get(col)) &&
                 (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row-1).get(col))))
         {
             System.out.print("win up and down");
             JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
         }
     }

     public  void checkUp2(int row,int col)
     {
         if((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row-1).get(col)) &&
                 (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row-2).get(col)))
         {
             System.out.println("win up");
             JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
         }
     }

    public  boolean checkHorizontal(int row, int col)
    {
        if(col == 0)
        {
            checkRight2(row,col);
        }
        else if(col == 1)
        {
            checkRight2(row, col);
            checkLeftRight(row, col);
        }
        else if(col == 2)
        {
            //Sy/
            checkLeft2(row,col);
            checkLeftRight(row,col);
        }
        else if(col == 3)
        {
            checkLeft2(row,col);
        }

        return false;
    }

    public  void checkRight2(int row, int col)
    {
        if(((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row).get(col+1))) &&
                (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row).get(col+2)))
        {
            System.out.println("win up");
            JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    public  void checkLeft2(int row, int col)
    {
        if(((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row).get(col-1))) &&
                (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row).get(col-2)))
        {
            System.out.println("win up");
            JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    public  void checkLeftRight(int row, int col)
    {
        if(((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row).get(col-1))) &&
                (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row).get(col+1)))
        {
            System.out.println("win up");
            JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
        }
    }

   public  boolean checkDiagonal(int row, int col)
    {
        if((row == 0 && col == 0) || (row == 0 && col == 1) ||  (row == 1 && col == 0))
        {
            upperLeft(row,col);
        }

        else if((row == 0 && col == 3) ||  (row == 1 && col == 3) || (row == 0 && col == 2))
        {
            upperRight(row,col);
        }

        else if((row == 3 && col == 3) || (row == 3 && col == 2) || (row == 2 && col == 2) || (row == 2 && col == 3))
        {
            bottomRight(row,col);
        }

        else if ((row == 3 && col == 0) || (row == 3 && col == 1) || (row == 2 && col == 0))
        {
            bottomLeft(row,col);
        }

        else if (row == 1 && col == 1)
        {
            upperLeft(row, col);
            middle1(row,col);
            middle2(row,col);
        }

        else if (row == 2 && col == 2)
        {
            bottomRight(row, col);
            middle1(row,col);
            middle2(row,col);
        }

        else if (row == 1 && col == 2)
        {
            upperRight(row, col);
            middle1(row,col);
            middle2(row,col);
        }

        else if (row == 2 && col == 1)
        {
            bottomLeft(row, col);
            middle1(row,col);
            middle2(row,col);
        }


        return false;
    }

    public void upperLeft(int row, int col)
    {
        if(((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row+1).get(col+1))) &&
                (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row+2).get(col+2)))
        {
            System.out.println("win up");
            JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    public void upperRight(int row, int col)
    {
        if(((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row+1).get(col-1))) &&
                (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row+2).get(col-2)))
        {
            System.out.println("win up");
            JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    public void bottomLeft(int row, int col)
    {
        if(((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row-1).get(col+1))) &&
                (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row-2).get(col+2)))
        {
            System.out.println("BL win up");
            JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    public void bottomRight(int row, int col)
    {
        if(((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row-1).get(col-1))) &&
                (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row-2).get(col-2)))
        {
            System.out.println("BR win up");
            JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    public void middle1 ( int row, int col)
    {
        if(((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row-1).get(col+1))) &&
                (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row+1).get(col-1)))
        {
            System.out.println(" middle 1 win up");
            JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    public void middle2 (int row, int col)
    {
        if(((virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row-1).get(col-1))) &&
                (virtualBoard.getVirtualBoard().get(row).get(col)).equals(virtualBoard.getVirtualBoard().get(row+1).get(col+1)))
        {
            System.out.println("middle 2 win up");
            JOptionPane.showMessageDialog(new JOptionPane("Win"), "WIN", "Results", JOptionPane.INFORMATION_MESSAGE);
        }
    }
    
     public void makeMove()
     {

     }

     public  boolean validMove(int row, int col, String val)
     {
         //check if the other player has used or not and also should not be more than 16 moves n than present the end screen

        return false;
    }

     public boolean checkWin()
     {
      return false;
     }


}
