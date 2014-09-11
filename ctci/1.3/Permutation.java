public class Permutation
{
	public static boolean permutation(String text1, String text2)
	{
		int i;
		if(text1.length()!=text2.length())
			return false;

		int[] count = new int[128];
		for(i=0;i<text1.length();i++)
			count[text1.charAt(i)]++;
		
		for(i=0;i<text2.length();i++)
			count[text2.charAt(i)]--;
			
		for(i=0;i<text1.length();i++)
			if(count[text1.charAt(i)]!=0)
				return false;
		return true;
	}
	
	public static void main(String[] args)
	{
		System.out.println(permutation("hello","oloeh"));
		System.out.println(permutation("hello","olleh"));
	}
}