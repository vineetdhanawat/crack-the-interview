public class Replace
{
	public static void replace(char[] text, int length)
	{
		int count=0, index;
		for(int i=0;i<length;i++)
			if(text[i] == ' ')
				count++;
		
		index = length + count*2;
		
		for(--length;length>=0;length--)
		{
			if(text[length]==' ')
			{
				text[index-1] = '0';
				text[index-2] = '2';
				text[index-3] = '%';
				index = index-3;
			}
			else
			{
				text[index-1] = text[length];
				index = index-1;
			}
		}
	}
	
	public static void main(String[] args)
	{
		String str = "abc d e f";
		char[] arr = new char[str.length() + 3*2];
		for (int i=0;i<str.length();i++)
		{
			arr[i] = str.charAt(i);
		}
		replace(arr, str.length());
		System.out.println(arr);
	}
}