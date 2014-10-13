import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;

public class DepthLinkedList{
	static ArrayList<LinkedList<TreeNode>> bfslist = new ArrayList<LinkedList<TreeNode>>();
	static ArrayList<LinkedList<TreeNode>> dfslist = new ArrayList<LinkedList<TreeNode>>();
	public static void main(String[] args){
		int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int length = array.length;
		TreeNode root = createMinimalBST(array,0,length-1);
		createBFSLinkedList(root);
		createDFSLinkedList(root,0);
		
		testPrint(bfslist);
		testPrint(dfslist);
		
	}

	public static void createDFSLinkedList(TreeNode root, int level) {
		if (root != null) {
			// Time for new list
			LinkedList<TreeNode> current = null;
			if(dfslist.size() == level) {
				current = new LinkedList<TreeNode>();
				dfslist.add(current);
			} else {
				current = dfslist.get(level);
			}
			current.add(root);
			createDFSLinkedList(root.getLeftNode(),level+1);
			createDFSLinkedList(root.getRightNode(),level+1);
		}
	}
	
	public static void createBFSLinkedList(TreeNode root) {
		LinkedList<TreeNode> current = new LinkedList<TreeNode>();
		if (root != null) {
			current.add(root);
		}
		while(current.size() > 0) {
			bfslist.add(current);
			LinkedList<TreeNode> parents = current;
			current = new LinkedList<TreeNode>();
			for(TreeNode parent : parents) {
				if (parent.getLeftNode() != null) {
					current.add(parent.getLeftNode());
				}
				if (parent.getRightNode() != null) {
					current.add(parent.getRightNode());
				}
			}
		}
	}
	
	public static void testPrint(ArrayList<LinkedList<TreeNode>> list) {
		int depth = 0;
		for(LinkedList<TreeNode> entry : list) {
			Iterator<TreeNode> i = entry.listIterator();
			System.out.print("Link list at depth " + depth + ":");
			while(i.hasNext()){
				System.out.print(" " + ((TreeNode)i.next()).getData());
			}
			System.out.println();
			depth++;
		}
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