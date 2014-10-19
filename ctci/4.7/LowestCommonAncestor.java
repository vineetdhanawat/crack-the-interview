import java.util.Arrays;

public class LowestCommonAncestor{
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
		
		lcaArray(root,getNode(root,1),getNode(root,5));
		System.out.println("LCA:"+optimizedLCA(root,getNode(root,1),getNode(root,5)).getData());

	}
	
	public static TreeNode optimizedLCA(TreeNode root, TreeNode first, TreeNode second) {
		if(root == null) return null;
		if(root.getData() == first.getData() || root.getData() == second.getData()) {
			return root;
		}
		TreeNode left = optimizedLCA(root.getLeftNode(),first,second);
		TreeNode right = optimizedLCA(root.getRightNode(),first,second);
		
		if(left != null && right != null) {
			return root;
		}
		
		return (left == null) ? left : right;
	}

	// store paths in two array and compare array
	public static void lcaArray(TreeNode root, TreeNode first, TreeNode second) {
		int[] array1 = new int[10];
		int[] array2 = new int[10];
		array1 = findPath(root, first);
		array2 = findPath(root, second);

		for(int i=0;i<array1.length;i++) {
			if(array1[i]!=array2[i]) {
				System.out.println("LCA:"+array1[i-1]);
				break;
			}
		}
	}
	
	// Assuming root and node are not same, else more cases
	public static int[] findPath(TreeNode root, TreeNode node){
		int[] array = new int[10];
		int count = 0;
		while(root.getData() != node.getData())
		{
			array[count] = root.getData();
			if(node.getData() < root.getData())
				root = root.getLeftNode();
			else
				root = root.getRightNode();
			count++;
		}
		array[count] = root.getData();
		
		return array;
	}

	public static TreeNode getNode(TreeNode root, int x) {
		if(root.getData() == x) return root;
		if(root.getData() > x) return getNode(root.getLeftNode(), x);
		else return getNode(root.getRightNode(), x);
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