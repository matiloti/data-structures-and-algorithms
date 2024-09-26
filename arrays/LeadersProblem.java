// https://www.geeksforgeeks.org/leaders-in-an-array/
public class LeadersProblem {
    
    /**
     * Print all leaders in an array. A number is a leader if
     * its greater than all the numbers to its right side.
     * 
     * Time complexity  : O(n)
     * Space complexity : O(1)
    **/
    private static void printAllLeaders(int[] arr) {
        // The maxNumber variable stores the current maximum number value from right to left
        int maxNumber = Integer.MIN_VALUE;
        
        // Print leaders numbers
        for(int i = arr.length - 1; 0 <= i ; i--) {
            if(arr[i] > maxNumber) {
                maxNumber = arr[i];
                System.out.print(arr[i] + " ");
            }
        }
        System.out.println();
    }
    
    public static void main(String args[]) {
        int[] arr1 = {1, 2, 3, 4, 5, 2};
        printAllLeaders(arr1);
      
        int[] arr2 = {6, 5, 4, 3, 2, 1};
        printAllLeaders(arr2);
    }
}
