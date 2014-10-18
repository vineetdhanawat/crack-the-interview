public class NextInorder{
	public static void main(String[] args){

		TreeNode root = new TreeNode(5);
		root.setLeftNode(new TreeNode(2));
		root.getLeftNode().setParentNode(root);
		root.setRightNode(new TreeNode(8));
		root.getRightNode().setParentNode(root);
		
		root.getLeftNode().setLeftNode(new TreeNode(1));
		root.getLeftNode().getLeftNode().setParentNode(root.getLeftNode());
		root.getLeftNode().setRightNode(new TreeNode(3));
		root.getLeftNode().getRightNode().setParentNode(root.getLeftNode());
		
		
		root.getRightNode().setLeftNode(new TreeNode(6));
		root.getRightNode().getLeftNode().setParentNode(root.getRightNode());
		root.getRightNode().setRightNode(new TreeNode(9));
		root.getRightNode().getRightNode().setParentNode(root.getRightNode());
		
		printInorder(root);
		next(root.getLeftNode().getRightNode());
	}
	
	public static void printInorder(TreeNode root) {
		if(root != null) {
			printInorder(root.getLeftNode());
			System.out.print(root.getData()+" ");
			printInorder(root.getRightNode());
		}
	}
	
	public static void next(TreeNode root) {
		if(root.getRightNode() != null) {
			TreeNode temp = root.getRightNode();
			while(temp.getLeftNode() != null) {
				temp = temp.getLeftNode();
			}
			System.out.print("Next of : "+root.getData()+" is: "+temp.getData());
		} else {
			TreeNode temp = root.getParentNode();
			while(temp.getParentNode().getRightNode() == null){
				temp = temp.getParentNode();
			}
			System.out.print("Next of : "+root.getData()+" is: "+temp.getParentNode().getData());
		}
	
	}
}

class TreeNode {
	private int data;
	private TreeNode leftNode;
	private TreeNode rightNode;
	private TreeNode parentNode;

	public TreeNode(int data) {
		this.data = data;
	}

	public int getData() {
		return this.data;
	}

	public void setLeftNode(TreeNode x) {
		this.leftNode = x;
	}
	
	public void setParentNode(TreeNode x) {
		this.parentNode = x;
	}

	public void setRightNode(TreeNode x) {
		this.rightNode = x;
	}
	
	public TreeNode getLeftNode() {
		return this.leftNode;
	}

	public TreeNode getParentNode() {
		return this.parentNode;
	}

	public TreeNode getRightNode() {
		return this.rightNode;
	}
}