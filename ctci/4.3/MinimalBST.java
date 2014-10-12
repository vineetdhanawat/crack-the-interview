import java.lang.Math;

public class MinimalBST{
	public static void main(String[] args){
		int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int length = array.length;
		TreeNode root = createMinimalBST(array,0,length-1);
		
		// TEST
		System.out.println(isBalanced(root));
	}
	
	public static TreeNode createMinimalBST(int[] array, int start, int end) {
		if(start<=end) {
			int mid = (start+end)/2;
			TreeNode node = new TreeNode(array[mid]);
			node.setLeftNode(createMinimalBST(array,start,mid-1));
			node.setRightNode(createMinimalBST(array,mid+1,end));
			return node;
		}
		return null;
	}

	// TEST method
	public static boolean isBalanced(TreeNode n){
		if(n==null)	return true;
		
		if(getHeight(n) == -1)
			return false;
		else
			return true;
	}

	// TEST method
	public static int getHeight(TreeNode n){
		if(n==null)	return 0;
		int leftHeight = getHeight(n.getLeftNode());
		if(leftHeight==-1)
			return -1;
		int rightHeight = getHeight(n.getRightNode());
		if(rightHeight==-1)
			return -1;

		if(Math.abs(leftHeight-rightHeight)>1)
			return -1;
		else
			return Math.max(leftHeight,rightHeight) + 1;

	}
}

class TreeNode {
	private int data;
	private TreeNode leftNode;
	private TreeNode rightNode;

	public TreeNode(int data) {
		this.data = data;
	}

	public void setLeftNode(TreeNode x) {
		this.leftNode = x;
	}

	public void setRightNode(TreeNode x) {
		this.rightNode = x;
	}
	
	public TreeNode getLeftNode() {
		return this.leftNode;
	}

	public TreeNode getRightNode() {
		return this.rightNode;
	}
}