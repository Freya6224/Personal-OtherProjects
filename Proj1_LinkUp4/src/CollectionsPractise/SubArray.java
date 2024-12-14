package CollectionsPractise;

import java.util.ArrayList;
import java.util.Scanner;

public class SubArray {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */

        Scanner userInput = new Scanner (System.in);

        int lengthArray = userInput.nextInt();

        ArrayList<Integer> list = new ArrayList<Integer>();

        for( int i=0; i < lengthArray; i++){
            list.add (userInput.nextInt());
        }

        // Logic for subarray.

        ArrayList< ArrayList<Integer> > subArray = new ArrayList<>();


        // 3d for loop.

        // Outer loop run n times.

        for ( int i = list.size(); i > 0; i--){
            //System.out.println("Value of i " + i);


           // int startPosition = -1;

            for (int j = 0; j < (list.size()-i) + 1 ; j++){
           //     System.out.println("Value of j " + j);

                ArrayList<Integer> row = new ArrayList<>();

               // System.out.println("Start Position: " + startPosition);

                for (int k =0; k < i; k++){
                   // System.out.println("Hello");
                    //System.out.println("Value of k" + k);
                    //System.out.println("value: " + (k+j));
                    row.add(list.get(k + j));
                }

                subArray.add(row);
           //     System.out.println("Array is " + row);

            }


        }

        System.out.println("Sub array is " + subArray);




        //  System.out.println("list is " + list);
    }


}
