import java.util.ArrayList;
import java.util.List;

public class Board
{
    private  List<List<String>> virtualBoard;

    public List<List<String>> getVirtualBoard() {
        return virtualBoard;
    }

//    public void setVirtualBoard(List<List<String>> virtualBoard) {
//        Board.virtualBoard = virtualBoard;
//    }

    public Board() {
        virtualBoard = new ArrayList<>(4);

        for(int i = 0; i < 4; i++)
        {
            //ArrayList<String> row = new ArrayList<>(4);
            List<String> row = new ArrayList<>(4);
            for(int j = 0; j < 4; j++)
            {
                row.add("-");
            }
            virtualBoard.add(row);
        }
    }
//
//    public void createBoard()
//    {
//        //List<String> row = new ArrayList<>(4);
//        virtualBoard = new ArrayList<>(4);
//
//        for(int i = 0; i < 4; i++)
//        {
//            //ArrayList<String> row = new ArrayList<>(4);
//            List<String> row = new ArrayList<>(4);
//            for(int j = 0; j < 4; j++)
//            {
//                row.add("-");
//            }
//            virtualBoard.add(row);
//        }
  //  }

    public  void displayBoard()
    {
        //System.out.println("Board is" + virtualBoard);
        for(int i = 0; i < virtualBoard.size(); i++)
        {
            for(int j = 0; j < virtualBoard.size(); j++)
            {
                //System.out.println(i + " " + j);
                System.out.print(virtualBoard.get(i).get(j) + "  ");
            }
            System.out.println();
        }
    }

    public  void updateBoard(int row, int col , String value)
    {
        virtualBoard.get(row).set(col,value);
        //System.out.print(virtualBoard.get(row).get(col));
        displayBoard();
    }

}

