public class Compression {

	public static String compression(String str)
	{
		String str2="";
		int i=0,count=0;
		char temp;
		while(i<str.length())
		{
			temp = str.charAt(i);
			count = 1;
			while(i<str.length()-1 && temp == str.charAt(i+1))
			{
				i++;count++;
			}
			str2 = str2 + temp+count;
			i++;
		}
		if(str2.length()<str.length())
			return str2;
		else
			return str;
	}
	
	public static void main(String[] args)
	{
		String str = "abbccccccde";
		String str2 = compression(str);
		System.out.println("Old String (len = " + str.length() + "): " + str);
		System.out.println("New String (len = " + str2.length() + "): " + str2);
	}
}