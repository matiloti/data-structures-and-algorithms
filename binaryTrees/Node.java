package matias.dsa.binaryTree;

public class Node<T> {
	T value;
	Node left;
	Node right;
	
	Node(T value) {
		this.value = value;
		this.left = null;
		this.right = null;
	}
}