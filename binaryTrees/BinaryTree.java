package matias.dsa.binaryTree;

import java.util.Queue;
import java.util.LinkedList;
import matias.dsa.binaryTree.Node;
import matias.dsa.binaryTree.BinaryTreeAlgorithms;

/**
 * @author Matias Luis Lotito Ralli
 * 
 * Basic class representation of a binary tree
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
	 * @param valueToInsert The value to insert
	**/
	public void insertNode(T valueToInsert) {
		this.root = BinaryTreeAlgorithms.insertNode(this.root, valueToInsert);
	}
	
	/**
	 * Checks if a value exists in the tree
	 * @param valueToSearch The value to search
	 * @return Whether the tree contains that value or not
	**/
	public boolean searchNode(T valueToSearch) {
		return BinaryTreeAlgorithms.searchNode(this.root, valueToSearch);
	}
	
	/**
	 * Delete a node containing the value to delete from the tree and replace it with the rightmost node
	 * @param valueToDelete The value to delete
	**/
	public void deleteNode(T valueToDelete) {
		this.root = BinaryTreeAlgorithms.deleteNode(this.root, valueToDelete);
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
¡	**/
	public void printPostorderDfs() {
		BinaryTreeAlgorithms.printPostorderDfs(this.root);
	}
	
	/**
	 * Print the binary tree with BFS algorithm
	**/
	public void printBfs() {
		BinaryTreeAlgorithms.printBfs(this.root);
	}
	
	// "Test" function
	public static void main(String args[]) {
		Node<Integer> root = new Node<>(1);
		root.left = new Node<Integer>(2);
		root.right = new Node<Integer>(3);
		root.left.left = new Node<Integer>(4);
		root.left.right = new Node<Integer>(5);
		root.right.left = new Node<Integer>(6);
		root.right.right = new Node<Integer>(7);
		
		BinaryTree<Integer> tree = new BinaryTree<>(root);
		System.out.println("Creating new tree with 7 nodes...");
		
		System.out.print("Tree before the round of insertions: ");
		tree.printPreorderDfs();
		tree.insertNode(8);
		System.out.print("\nTree after insertion of value 8: ");
		tree.printPreorderDfs();
		tree.insertNode(9);
		System.out.print("\nTree after insertion of value 9: ");
		tree.printPreorderDfs();
		tree.insertNode(10);
		System.out.print("\nTree after insertion of value 10: ");
		tree.printPreorderDfs();
		tree.insertNode(11);
		System.out.print("\nTree after insertion of value 11: ");
		tree.printPreorderDfs();
		tree.insertNode(12);
		System.out.print("\nTree after insertion of value 12: ");
		tree.printPreorderDfs();
		tree.insertNode(13);
		System.out.print("\nTree after insertion of value 13: ");
		tree.printPreorderDfs();
		tree.insertNode(null);
		System.out.print("\nTree after insertion of value null: ");
		tree.printPreorderDfs();
		
		
		System.out.println("\nThe value 1 " + (tree.searchNode(1) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 2 " + (tree.searchNode(2) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 3 " + (tree.searchNode(3) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 4 " + (tree.searchNode(4) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 5 " + (tree.searchNode(5) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 6 " + (tree.searchNode(6) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 7 " + (tree.searchNode(7) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 8 " + (tree.searchNode(8) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 9 " + (tree.searchNode(9) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 10 " + (tree.searchNode(10) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 11 " + (tree.searchNode(11) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 12 " + (tree.searchNode(12) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 13 " + (tree.searchNode(13) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 14 " + (tree.searchNode(14) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 15 " + (tree.searchNode(15) ? "exists" : "does not exist") + " in the tree");
		System.out.println("The value 20 " + (tree.searchNode(20) ? "exists" : "does not exist") + " in the tree");
		
		System.out.print("Tree before the round of deletions: ");
		tree.printPreorderDfs();
		tree.deleteNode(8);
		System.out.print("\nTree after deletion of value 8: ");
		tree.printPreorderDfs();
		tree.deleteNode(9);
		System.out.print("\nTree after deletion of value 9: ");
		tree.printPreorderDfs();
		tree.deleteNode(10);
		System.out.print("\nTree after deletion of value 10: ");
		tree.printPreorderDfs();
		tree.deleteNode(11);
		System.out.print("\nTree after deletion of value 11: ");
		tree.printPreorderDfs();
		tree.deleteNode(12);
		System.out.print("\nTree after deletion of value 12: ");
		tree.printPreorderDfs();
		tree.deleteNode(13);
		System.out.print("\nTree after deletion of value 13: ");
		tree.printPreorderDfs();
		tree.deleteNode(1);
		System.out.print("\nTree after deletion of value 1: ");
		tree.printPreorderDfs();
		tree.deleteNode(1);
		System.out.print("\nTree after deletion of value 1: ");
		tree.printPreorderDfs();
		tree.deleteNode(123);
		System.out.print("\nTree after deletion of value 123: ");
		tree.printPreorderDfs();
		
		
		System.out.println("\nCreating a tree with just a root node of value 1...");
		BinaryTree<Integer> treeWithJustOneNode = new BinaryTree<>(new Node<Integer>(1));
		System.out.println("Tree before performing actions to it: ");
		treeWithJustOneNode.printPreorderDfs();
		treeWithJustOneNode.deleteNode(1);
		System.out.print("\nTree with one node after deletion of value 1: ");
		treeWithJustOneNode.printPreorderDfs();
		
		treeWithJustOneNode.insertNode(13);
		System.out.print("\nTree with no nodes after insertion of value 13: ");
		treeWithJustOneNode.printPreorderDfs();
		treeWithJustOneNode.insertNode(14);
		System.out.print("\nTree with one node after insertion of value 14: ");
		treeWithJustOneNode.printPreorderDfs();
		treeWithJustOneNode.insertNode(15);
		System.out.print("\nTree with two nodes after insertion of value 15: ");
		treeWithJustOneNode.printPreorderDfs();
	}
}
