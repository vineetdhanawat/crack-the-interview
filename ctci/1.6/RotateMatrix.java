import java.util.Random;
import java.lang.Math;

public class RotateMatrix
{	
	public static int N=4;
	public static void RotateMatrix(int[][] matrix)
	{
		int temp;
		for(int i=0;i<N/2;i++)
		{
			for(int j=i;j<=(N-i)/2;j++)
			{
				temp = matrix[i][j];
				
				// left to top
				matrix[i][j] = matrix[N-1-j][i];
				// bottom to left
				matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
				// right to bottom
				matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
				// top to right
				matrix[j][N-1-i] = temp;
			}
		}
	}
	
	public static void print(int[][] matrix)
	{
		System.out.println();
		for (int row=0;row<N;row++)
		{
			for (int col=0;col<N;col++)
			{
				System.out.print(matrix[row][col]+" ");
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args)
	{	
		Random rn = new Random();
		int matrix[][] = new int[N][N];
		for (int row=0;row<N;row++)
		for (int col=0;col<N;col++)
		{
			int i = rn.nextInt() % 10;
			matrix[row][col] = Math.abs(i);
		}
		print(matrix);
		RotateMatrix(matrix);
		print(matrix);
	}
}