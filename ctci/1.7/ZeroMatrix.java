import java.util.Random;
import java.lang.Math;

public class ZeroMatrix
{	
	public static int M=4;
	public static int N=5;
	public static void ZeroMatrix(int[][] matrix)
	{
		boolean[] row = new boolean[M];
		boolean[] col = new boolean[N];

		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(matrix[i][j] == 0)
				{
					row[i] = true;
					col[j] = true;
				}
			}
		}
		
		for(int i=0;i<M;i++)
		{
			if(row[i])
			{
				for(int j=0;j<N;j++)
				matrix[i][j] = 0;
			}
		}
		
		for(int j=0;j<N;j++)
		{
			if(col[j])
			{
				for(int i=0;i<M;i++)
				matrix[i][j] = 0;
			}
		}
	}
	
	public static void print(int[][] matrix)
	{
		System.out.println();
		for (int row=0;row<M;row++)
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
		int matrix[][] = new int[M][N];
		for (int row=0;row<M;row++)
		for (int col=0;col<N;col++)
		{
			int i = rn.nextInt() % 10;
			matrix[row][col] = Math.abs(i);
		}
		print(matrix);
		ZeroMatrix(matrix);
		print(matrix);
	}
}