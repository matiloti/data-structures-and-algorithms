package matias.dsa.binaryTree;

/**
 * @author Matias Luis Lotito Ralli
 * 
 * Basic class representation of a node
**/
public class Node<T> {
	T value;
	Node<T> left;
	Node<T> right;
	
	Node(T value) {
		this.value = value;
		this.left = null;
		this.right = null;
	}
	
	public boolean equals(Node otherNode) {
		return this.value.equals(otherNode.value);
	}
	
}