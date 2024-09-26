package matias.dsa.binaryTree;

import java.util.Queue;
import java.util.LinkedList;
import matias.dsa.binaryTree.Node;

/**
 * @author Matias Luis Lotito Ralli
 * 
 * Class implementing binary tree traversal algorithms
**/
public class BinaryTreeAlgorithms  {
	
	/* ----------------------------*/
	/* --- BASIC OPERATIONS ---*/
	/* ----------------------------*/
    
    /**
     * Inserts a new node into the tree
	 * @param root The root node
     * @param nodeToInsert The node to insert
    **/
    public static void insertNode(Node root, Node nodeToInsert) {
        // If the root node is null, return
        if(root == null) {
            return;
        }
        
        // Insert the new node into the first empty space on the leftmost side of the tree
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()) {
            Node currentNode = q.poll();
            if(currentNode.left == null) {
                currentNode.left = nodeToInsert;
				break;
            } else if(currentNode.right == null) {
                currentNode.right = nodeToInsert;
				break;
            } else {
                q.add(currentNode.left);
                q.add(currentNode.right);
            }
        }
    }
    
    /**
     * Checks if a node exists in a given tree
     * @param root The root node of the tree
     * @param nodeToInsert The node to insert
	 * @return Whether the tree contains that value or not
    **/
    public static boolean searchNode(Node root, Node nodeToSearch) {
		if(root == null) {
			return false;
		}
		
		if(root.equals(nodeToSearch)) {
			return true;
		}
		
		return searchNode(root.left, nodeToSearch) || searchNode(root.right, nodeToSearch);
	}
	
	/* ----------------------------*/
	/* --- TRAVERSAL ALGORITHMS---*/
	/* ----------------------------*/
    
    /**
     * Given a binary tree, traverse it with DFS (preorder) algorithm
     * @param root The root node of the tree
    **/
    public static void printPreorderDfs(Node root) {
        if(root == null) {
            return;
        }
        System.out.print(root.value + " ");
        printPreorderDfs(root.left);
        printPreorderDfs(root.right);
    }
    
    /**
     * Given a binary tree, traverse it with DFS (inorder) algorithm
     * @param root The root node of the tree
    **/
    public static void printInorderDfs(Node root) {
        if(root == null) {
            return;
        }
        printInorderDfs(root.left);
        System.out.print(root.value + " ");
        printInorderDfs(root.right);
    }
    
    /**
     * Given a binary tree, traverse it with DFS (postorder) algorithm
     * @param root The root node of the tree
    **/
    public static void printPostorderDfs(Node root) {
        if(root == null) {
            return;
        }
        printPostorderDfs(root.right);
        printPostorderDfs(root.left);
        System.out.print(root.value + " ");
    }
    
    /**
     * Given a binary tree, traverse it with BFS algorithm
     * @param root The root node of the tree
    **/
    public static void printBfs(Node root) {
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        
        while(!q.isEmpty()) {
            Node currentNode = q.poll();
            if(currentNode != null) {
                System.out.print(currentNode.value + " ");
                q.add(currentNode.left);
                q.add(currentNode.right);
            }
        }
    }
    
    public static void main(String args[]) {
        Node<Integer> root = new Node<>(1);
        root.left = new Node<Integer>(2);
        root.right = new Node<Integer>(3);
        root.left.left = new Node<Integer>(4);
        root.left.right = new Node<Integer>(5);
        root.right.left = new Node<Integer>(6);
        root.right.right = new Node<Integer>(7);
        
        System.out.print("DFS (Preorder): ");
        printPreorderDfs(root);
        System.out.print("\nDFS (Inorder): ");
        printInorderDfs(root);
        System.out.print("\nDFS (Postorder): ");
        printPostorderDfs(root);
        System.out.print("\nBFS: ");
        printBfs(root);
    }
}
