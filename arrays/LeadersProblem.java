// https://www.geeksforgeeks.org/leaders-in-an-array/
public class LeadersProblem {
    
    /**
     * Print all leaders in an array. A number is a leader if
     * its greater than all the numbers to its right side.
     * 
     * Time: O(n)
    **/
    private static void printAllLeaders(int[] arr) {
        // Leaders array can be as long as the original array (we could print it as we iterate through the array
        // but let's assume we want to preserve the solution)
        int[] leaders = new int[arr.length];
        
        // The maxNumber variable stores the current maximum number value from right to left
        int maxNumber = Integer.MIN_VALUE;
        
        // The numbers of leaders actually found
        int numberOfLeaders = 0;
        
        // Construct the leaders array
        for(int i = arr.length - 1; 0 <= i ; i--) {
            if(arr[i] > maxNumber) {
                maxNumber = arr[i];
                leaders[numberOfLeaders++] = maxNumber;
            }
        }
        
        // Print the leaders array
        for(int i = 0; i < numberOfLeaders; i++) {
            System.out.print(leaders[i] + " ");
        }
    }
    
    public static void main(String args[]) {
        int[] arr = {1, 2, 3, 4, 5, 2};
        printAllLeaders(arr);
      
        int[] arr = {6, 5, 4, 3, 2, 1};
        printAllLeaders(arr);
    }
}
