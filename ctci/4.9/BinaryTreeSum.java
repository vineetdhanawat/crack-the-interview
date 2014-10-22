
public class BinaryTreeSum{
	public static void main(String[] args){
		int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
		int length = array.length;
		TreeNode root = createMinimalBST(array,0,length-1);
		int[] path = new int[length];
		calculateSum(root,path,0,0,0,14);
	}
	
	public static TreeNode createMinimalBST(int[] array, int start, int end) {
		if(start<=end) {
			int mid = (start+end)/2;
			TreeNode node = new TreeNode(array[mid]);
			node.leftNode = (createMinimalBST(array,start,mid-1));
			node.rightNode = (createMinimalBST(array,mid+1,end));
			return node;
		}
		return null;
	}
	public static boolean calculateSum(TreeNode root, int[] path, int startIndex, int count, int tempSum, int sum) {
		if(root == null) return false;
		path[count] = root.data;
		count++;
		tempSum += root.data;
		if(tempSum == sum) {
			System.out.println("Sum Found");
			for(int j=startIndex;j<count;j++)
			{
				System.out.println(path[j]+" ");
			}
			return true;
		}
		if(tempSum > sum) {
			while(tempSum > sum) {
				tempSum -= path[startIndex];
				startIndex++;
			}
		}
		return calculateSum(root.leftNode,path,startIndex,count,tempSum,sum) || calculateSum(root.rightNode,path,startIndex,count,tempSum,sum);
	}
}

class TreeNode {
	public int data;
	public TreeNode leftNode;
	public TreeNode rightNode;

	public TreeNode(int data) {
		this.data = data;
	}
}