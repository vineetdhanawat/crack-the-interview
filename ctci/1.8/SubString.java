public class SubString
{
	public static boolean isSubstring(String first, String second)
	{
		if(first.contains(second))
			return true;
		else
			return false;
	}
	public static boolean isRotation(String first, String second)
	{
		if(first.length() == second.length())
		{
			first = first + first;
			return isSubstring(first,second);
		}
		return false;
	}
	
	public static void main(String[] args)
	{
		String[][] list = {{"waterbottle","erbottlewat"}};
		for(String[] entry : list)
		{
			String first = entry[0];
			String second = entry[1];
			System.out.println(isRotation(first,second));
		}
	}
}