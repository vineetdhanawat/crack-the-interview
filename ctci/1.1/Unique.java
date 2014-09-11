public class Unique
{
	public static boolean unique(String text)
	{
		int i;
		boolean[] count = new boolean[128];
		for(i=0;i<text.length();i++)
			if(count[text.charAt(i)])
				return false;
			else
				count[text.charAt(i)] = true;
		return true;
	}
	
	public static void main(String[] args)
	{
		System.out.println(unique("hello"));
		System.out.println(unique("helo"));
	}
}