package matias.dsa.binaryTree;

import java.util.Queue;
import java.util.LinkedList;
import matias.dsa.binaryTree.Node;
import matias.dsa.binaryTree.BinaryTreeAlgorithms;

/**
 * @author Matias Luis Lotito Ralli
 * 
 * Class implementing binary tree behaviours
**/
public class BinaryTree<T> {
	
	private Node<T> root;
	
	public BinaryTree(Node<T> root) {
		this.root = root;
	}
	
	public Node getRoot() {
		return this.root;
	}
	
	/* ----------------------------*/
	/* ---- BASIC OPERATIONS ---*/
	/* ----------------------------*/
    
    /**
     * Inserts a new node into the tree
     * @param nodeToInsert The node to insert
    **/
    public void insertNode(Node nodeToInsert) {
		BinaryTreeAlgorithms.insertNode(this.root, nodeToInsert);
    }
    
    /**
     * Checks if a node exists in the tree
     * @param nodeToSearch The node to search
	 * @return Whether the tree contains that value or not
    **/
    public boolean searchNode(Node nodeToSearch) {
		return BinaryTreeAlgorithms.searchNode(this.root, nodeToSearch);
	}
	
	/* ----------------------------*/
	/* --- TRAVERSAL ALGORITHMS ---*/
	/* ----------------------------*/
    
    /**
     * Print the binary tree with DFS (preorder) algorithm
    **/
    public void printPreorderDfs() {
		BinaryTreeAlgorithms.printPreorderDfs(this.root);
    }
    
    /**
     * Print the binary tree with DFS (inorder) algorithm
    **/
    public void printInorderDfs() {
		BinaryTreeAlgorithms.printInorderDfs(this.root);
    }
    
    /**
     * Print the binary tree with DFS (postorder) algorithm
¡    **/
    public void printPostorderDfs() {
		BinaryTreeAlgorithms.printPostorderDfs(this.root);
    }
    
    /**
     * Print the binary tree with BFS algorithm
    **/
    public void printBfs() {
		BinaryTreeAlgorithms.printBfs(this.root);
    }
    
    public static void main(String args[]) {
        Node<Integer> root = new Node<>(1);
        root.left = new Node<Integer>(2);
        root.right = new Node<Integer>(3);
        root.left.left = new Node<Integer>(4);
        root.left.right = new Node<Integer>(5);
        root.right.left = new Node<Integer>(6);
        root.right.right = new Node<Integer>(7);
		
		BinaryTree<Integer> tree = new BinaryTree<>(root);
        
        System.out.print("Tree before: ");
		tree.printPreorderDfs();
		tree.insertNode(new Node<Integer>(8));
		tree.insertNode(new Node<Integer>(9));
		tree.insertNode(new Node<Integer>(10));
		tree.insertNode(new Node<Integer>(11));
		tree.insertNode(new Node<Integer>(12));
		tree.insertNode(new Node<Integer>(13));
        System.out.print("\nTree after: ");
		tree.printPreorderDfs();
    }
}
