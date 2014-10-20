
public class SubTree{
	public static void main(String[] args){
		int[] array1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
		int[] array2 = {1, 2, 3, 4, 5, 6};
		int length1 = array1.length;
		TreeNode root1 = createMinimalBST(array1,0,length1-1);
		int length2 = array2.length;
		TreeNode root2 = createMinimalBST(array2,0,length2-1);

		System.out.println(containsTree(root1, root2));
	}

	// Assuming t1 tree is larger than t2
	public static boolean containsTree(TreeNode t1, TreeNode t2) {
		if (t2 == null) return true;
		if (t1 == null) return false;
		if (t1.getData() == t2.getData()) {
			if (matchElements(t1,t2)) return true;
		}
		return (containsTree(t1.getLeftNode(), t2) || containsTree(t1.getRightNode(), t2)); 
	}

	public static boolean matchElements(TreeNode t1, TreeNode t2) {
		if (t2 == null && t1 == null) 
			return true;
		if (t1 == null || t2 == null) 
			return false;
		if (t1.getData() != t2.getData()) 
			return false;
		return (matchElements(t1.getLeftNode(), t2.getLeftNode()) && matchElements(t1.getRightNode(), t2.getRightNode()));
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