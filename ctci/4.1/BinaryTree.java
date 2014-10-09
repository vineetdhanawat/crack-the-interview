import java.lang.Math;

public class BinaryTree{
	public static void main(String[] args){
	
		TreeNode root = new TreeNode(1);
		root.setLeftChild(new TreeNode(2));
		root.setRightChild(new TreeNode(3));
		
		root.left.setLeftChild(new TreeNode(4));
		root.left.setRightChild(new TreeNode(5));
		root.right.setLeftChild(new TreeNode(6));
		root.right.setRightChild(new TreeNode(7));
		
		root.left.left.setLeftChild(new TreeNode(8));
		root.left.left.left.setLeftChild(new TreeNode(9));
		
		System.out.println(isBalanced(root));
	}
	
	// O(N) time algo
	public static int getHeight(TreeNode n){
		if(n==null)	return 0;
		int leftHeight = getHeight(n.left);
		if(leftHeight==-1)
			return -1;
		int rightHeight = getHeight(n.right);
		if(rightHeight==-1)
			return -1;

		if(Math.abs(leftHeight-rightHeight)>1)
			return -1;
		else
			return Math.max(leftHeight,rightHeight) + 1;

	}
	
	public static boolean isBalanced(TreeNode n){
		if(n==null)	return true;
		
		if(getHeight(n) == -1)
			return false;
		else
			return true;
	}

	// O(N2) time algo
	public static int getHeight2(TreeNode n){
		if(n==null)	return 0;
		else{
			return Math.max(getHeight2(n.left),getHeight2(n.right)) + 1;
		}
	}
	
	public static boolean isBalanced2(TreeNode n){
		if(n==null)	return true;
		
		if(Math.abs(getHeight2(n.left)-getHeight2(n.right))>1)
			return false;
		else
			return (isBalanced2(n.left) && isBalanced2(n.right));
	}
}

class TreeNode{
	public int data;      
	public TreeNode left;    
	public TreeNode right;
	public TreeNode parent;

	public TreeNode(int d){
		data = d;
	}

	public void setLeftChild(TreeNode left){
		this.left = left;
	}
	
	public void setRightChild(TreeNode right){
		this.right = right;
	}
} 