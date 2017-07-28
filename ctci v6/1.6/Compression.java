public class Compression {

  public static String printCompression(String a) {
    String compressedString="";
    System.out.println(a.length());
    int count=1;
    for(int i=1;i<a.length();i++) {
      if(a.charAt(i) != a.charAt(i-1)){
        compressedString = compressedString + a.charAt(i-1)+count;
        System.out.println(a.charAt(i-1)+":"+count);
        count = 1;
      } else {
        count++;
      }
    }
    compressedString = compressedString + a.charAt(a.length()-1)+count;
    return a.length() < compressedString.length() ? a : compressedString;
  }

  public static void main(String[] args) {
    System.out.println(printCompression("aabcccccaaa"));
    System.out.println(printCompression("ab"));
  }
}
