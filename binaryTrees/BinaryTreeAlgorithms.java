package matias.dsa.binaryTree;

import java.util.Queue;
import java.util.LinkedList;
import matias.dsa.binaryTree.Node;

/**
 * @author Matias Luis Lotito Ralli
 * 
 * Class with binary tree common algorithms
**/
public class BinaryTreeAlgorithms  {
	
	/* ----------------------------*/
	/* --- BASIC OPERATIONS ---*/
	/* ----------------------------*/
	
	/**
	 * Inserts a new node with the given value into the tree
	 *
	 * Time complexity: O(n)
	 *
	 * @param root The root node
	 * @param valueToInsert The value to insert
	**/
	public static <T> Node<T> insertNode(Node<T> root, T valueToInsert) {
		// If the value to insert is null, return root
		if(valueToInsert == null) {
			return root;
		}
		
		/*
		If the root is null and the value to insert is not null,
		then the new tree is the value to insert
		*/
		if(root == null) {
			return new Node<T>(valueToInsert);
		}
		
		// Insert the new node into the first empty space on the leftmost side of the tree
		Queue<Node<T>> q = new LinkedList<>();
		q.add(root);
		while(!q.isEmpty()) {
			Node<T> currentNode = q.poll();
			if(currentNode.left == null) {
				currentNode.left = new Node<T>(valueToInsert);
				break;
			} else if(currentNode.right == null) {
				currentNode.right = new Node<T>(valueToInsert);
				break;
			}
			q.add(currentNode.left);
			q.add(currentNode.right);
		}
		
		// Return the modified root with the inserted value
		return root;
	}
	
	/**
	 * Checks if a value exists in a given tree
	 *
	 * Time complexity: O(n)
	 *
	 * @param root The root node of the tree
	 * @param valueToSearch The value to search
	 * @return Whether the tree contains that value or not
	**/
	public static <T> boolean searchNode(Node<T> root, T valueToSearch) {
		// If the root node or the node to search is null, return false
		if(root == null || valueToSearch == null) {
			return false;
		}
		
		// If the root value equals the value to search, then the value exists
		if(root.value.equals(valueToSearch)) {
			return true;
		}
		
		// Otherwise explore first the left branch of the tree and then the right branch
		return searchNode(root.left, valueToSearch) || searchNode(root.right, valueToSearch);
	}
	
	/**
	 * Delete the node with the given value from the tree and replace it with the rightmost node.
	 * 
	 * Time complexity: O(n)
	 *
	 * @param root The root node
	 * @param valueToDelete The value to delete
	**/
	public static <T> Node<T> deleteNode(Node<T> root, T valueToDelete) {
		/*
		If the root node or the node to delete are null, return the root,
		as if the root is null there is nothing to delete, so null should
		be returned, and as if the value to delete is null there is nothing
		to delete either so the root unchanged should be returned too
		*/
		if(root == null || valueToDelete == null) {
			return root;
		}
		
		// Find the target node (the node to delete) and the rightmost node and its parent
		Node<T> targetNode = null;
		Node<T> rightmostNode = null;
		Node<T> parentOfRightmostNode = null;
		Queue<Node<T>> q = new LinkedList<>();
		Queue<Node<T>> parentQueue = new LinkedList<>();
		q.add(root); // The first node is the root
		parentQueue.add(null); // The parent of the root is null (as it does not have a parent)
		while(!q.isEmpty()) {
			// Get the current node and its parent
			Node<T> currentNode = q.poll();
			Node<T> currentParent = parentQueue.poll();
			
			// If current node is null, continue the loop
			if(currentNode == null) {
				continue;
			}
			
			// If the node to delete is finded, save the reference to it
			if(currentNode.value.equals(valueToDelete)) {
				targetNode = currentNode;
			}
			
			// Add the left child and its parent to the queue for continuing the tree traversal
			q.add(currentNode.left);
			parentQueue.add(currentNode);
			
			// Add the right child and its parent to the queue for continuing the tree traversal
			q.add(currentNode.right);
			parentQueue.add(currentNode);
			
			// At the end of the traversal, the last node visited will be the rightmost node (same for the parent)
			rightmostNode = currentNode;
			parentOfRightmostNode = currentParent;
		}
		
		/* --- SPECIAL CASES --- */
		
		/*
		If the node to delete does not exist in the tree, 
		then the tree remains unchanged and must be returned
		*/
		if(targetNode == null) {
			return root;
		}
		
		/*
		If the parent of rightmost node is null,
		this means that the target node is the root node,
		as it's the only node without parent, and the only way 
		to remove the root node is to return null as 
		the new tree root
		*/
		if(parentOfRightmostNode == null) {
			return null;
		}
		
		/* --- REMOVE THE TARGET NODE --- */
		
		/*
		Overwrite the value of the target node with that of 
		the rightmost node to effectively 'remove' it (indeed, the 
		value of the node to delete is replaced by the value 
		of the rightmost node). 
		
		If target node and rightmost node are equal, this step can 
		be skipped, but as this step is harmless we do it anyway
		because an "if" condition is removed (if they are equal,
		overwriting two equal values results in the same)
		*/
		targetNode.value = rightmostNode.value;
		
		/*
		The parent is used to overwrite the reference
		to the rightmost node to null so it get's effectively deleted
		*/
		if(parentOfRightmostNode.left != null && parentOfRightmostNode.left.equals(rightmostNode)) {
			parentOfRightmostNode.left = null;
		} else {
			parentOfRightmostNode.right = null;
		}
		
		// Return the modified tree with the deleted node
		return root;
		
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
}
