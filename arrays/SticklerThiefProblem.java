// https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
public class SticklerThiefProblem  {
    
    /**
     * Given an array arr[] of positive numbers, The task is to 
     * find the maximum sum of a subsequence such that no 2 
     * numbers in the sequence should be adjacent in the array.
     * 
     * Time complexity  : O(n)
     * Space complexity : O(n)
    **/
    private static void printMaxSum(int[] arr) {
        
        int solution = 0; // Default solution is 0 when array is empty or null

        if(arr == null) {
            System.out.println(solution);
            return;
        }
        
        int n = arr.length;
        
        if(n == 1) {
            // If n is 1, then the max sum is the only element
            solution = arr[0];
        } else if(n == 2) {
            // If n is 1, then the max sum is the maximum element of both unique elements
            solution = Math.max(arr[0], arr[1]);
        } else if(n > 2) {
            // If n is equal or greater than 2, then we must calculate the solution dynamically
            int[] dynamicProgrammingSolution = new int[n];
            dynamicProgrammingSolution[0] = arr[0]; // Base case 1
            dynamicProgrammingSolution[1] = Math.max(arr[0], arr[1]); // Base case 2
            
            // Dynamically calculate the solution
            for(int i = 2; i < n; i++) {
                int sumIfCurrentValueIsSelected = arr[i] + dynamicProgrammingSolution[i - 2];
                
                int sumIfCurrentValueIsNotSelected = dynamicProgrammingSolution[i - 1];
                
                dynamicProgrammingSolution[i] = Math.max(sumIfCurrentValueIsSelected, sumIfCurrentValueIsNotSelected);
            }
            
            // Solution is at the end of the array
            solution = dynamicProgrammingSolution[n - 1];
        }
        
        System.out.println(solution);
    }
    
    public static void main(String args[]) {
        
        // Expected 0
        printMaxSum(null);
        
        // Expected 1
        int[] arr1 = {1};
        printMaxSum(arr1);
        
        // Expected 2
        int[] arr2 = {1, 2};
        printMaxSum(arr2);
        
        // Expected 9
        int[] arr3 = {1, 2, 3, 4, 5, 2};
        printMaxSum(arr3);
      
        // Expected 12
        int[] arr4 = {6, 5, 4, 3, 2, 1};
        printMaxSum(arr4);
        
        // Expected 110
        int[] arr5 = {5, 5, 10, 100, 10, 5};
        printMaxSum(arr5);
        
        // Expected 13
        int[] arr6 = {3, 2, 7, 10};
        printMaxSum(arr6);
        
        // Expected 15
        int[] arr7 = {3, 2, 5, 10, 7};
        printMaxSum(arr7);
    }
}
