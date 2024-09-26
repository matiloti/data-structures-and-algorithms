import java.util.Queue;
import java.util.LinkedList;

/**
 * @author Matias Luis Lotito Ralli
 * 
 * Class implementing binary tree traversal algorithms
**/
public class BinaryTreeTraversalAlgorithms  {
    
    static class Node {
        int value;
        Node left;
        Node right;
        
        Node(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }    
    
    /**
     * Given a binary tree, traverse it with DFS (prenorder) algorithm
     * @param root The root node of the tree
    **/
    private static void dfsBinaryTreeAlgorithmPreorder(Node root) {
        if(root == null) {
            return;
        }
        System.out.print(root.value);
        dfsBinaryTreeAlgorithmPreorder(root.left);
        dfsBinaryTreeAlgorithmPreorder(root.right);
    }
    
    /**
     * Given a binary tree, traverse it with DFS (inorder) algorithm
     * @param root The root node of the tree
    **/
    private static void dfsBinaryTreeAlgorithmInorder(Node root) {
        if(root == null) {
            return;
        }
        dfsBinaryTreeAlgorithmInorder(root.left);
        System.out.print(root.value);
        dfsBinaryTreeAlgorithmInorder(root.right);
    }
    
    /**
     * Given a binary tree, traverse it with DFS (postnorder) algorithm
     * @param root The root node of the tree
    **/
    private static void dfsBinaryTreeAlgorithmPostorder(Node root) {
        if(root == null) {
            return;
        }
        dfsBinaryTreeAlgorithmPostorder(root.right);
        dfsBinaryTreeAlgorithmPostorder(root.left);
        System.out.print(root.value);
    }
    
    /**
     * Given a binary tree, traverse it with BFS algorithm
     * @param root The root node of the tree
    **/
    private static void bfsBinaryTreeAlgorithm(Node root) {
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        
        while(!q.isEmpty()) {
            Node currentNode = q.poll();
            if(currentNode != null) {
                System.out.print(currentNode.value);
                q.add(currentNode.left);
                q.add(currentNode.right);
            }
        }
    }
    
    public static void main(String args[]) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        
        System.out.print("DFS (Preorder): ");
        dfsBinaryTreeAlgorithmPreorder(root);
        System.out.print("\nDFS (Inorder): ");
        dfsBinaryTreeAlgorithmInorder(root);
        System.out.print("\nDFS (Postorder): ");
        dfsBinaryTreeAlgorithmPostorder(root);
        System.out.print("\nBFS: ");
        bfsBinaryTreeAlgorithm(root);
    }
}
