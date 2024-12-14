package CollectionsPractise;

import java.util.*;

public class Generics {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */


        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();

        // System.out.println("Number is " + n);

        // // Creating 2d Array:

        ArrayList<ArrayList<Integer>> rows = new ArrayList<>();

        for (int i = 0; i < n; i++) {

            int totalItems = scan.nextInt();

            ArrayList<Integer> row = new ArrayList<>();


             System.out.println("Total items " + totalItems);

            for (int j = 0; j < totalItems; j++) {

                int item = scan.nextInt();

                System.out.println("Item is " + item);
                row.add(item);
                System.out.println("ROw item is " + row.get(j));
            }

            // rows.add(row);


            // System.out.println("Row is " + rows.get(i));
        }

    }
}