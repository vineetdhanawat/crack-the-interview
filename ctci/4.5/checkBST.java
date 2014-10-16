public class checkBST{
	public static void main(String[] args){

		TreeNode root = new TreeNode(5);
		root.setLeftNode(new TreeNode(2));
		root.setRightNode(new TreeNode(8));
		
		root.getLeftNode().setLeftNode(new TreeNode(1));
		root.getLeftNode().setRightNode(new TreeNode(3));
		root.getRightNode().setLeftNode(new TreeNode(6));
		root.getRightNode().setRightNode(new TreeNode(9));
		
		System.out.println(checkBST(root,Integer.MIN_VALUE,Integer.MAX_VALUE));
		
	}
	
	public static boolean checkBST(TreeNode root, int min, int max) {
		if(root == null) return true;
		if(root.getData() < max && root.getData() > min){
			return checkBST(root.getLeftNode(), min, root.getData()) && checkBST(root.getRightNode(), root.getData(), max);
		} else
			return false;
	}
}

class TreeNode {
	private int data;
	private TreeNode leftNode;
	private TreeNode rightNode;

	public TreeNode(int data) {
		this.data = data;
	}

	public int getData() {
		return this.data;
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