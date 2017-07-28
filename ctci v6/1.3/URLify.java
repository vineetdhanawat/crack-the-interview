public class URLify {

  public static char[] convertString(String a, int b) {
    char[] ch = a.toCharArray();
    int spaceCount=0;
    for(int i=0;i<b;i++) {
      if(ch[i] == ' ')
        spaceCount++;
    }
    System.out.println(spaceCount);
    // new length needed
    spaceCount = b + spaceCount*2;
    for (int i=b-1;i>=0;i--) {
      if(ch[i] == ' ') {
        ch[spaceCount-1]='0';
        ch[spaceCount-2]='2';
        ch[spaceCount-3]='%';
        spaceCount-=3;
      } else {
        ch[spaceCount-1]=ch[i];
        spaceCount--;
      }
    }
    return ch;
  }
  public static void main(String[] args) {
    //String.valueOf(data);
    // Enough empty spaces in string

    System.out.println(convertString("Mr John Smith    ",13));
  }
}
