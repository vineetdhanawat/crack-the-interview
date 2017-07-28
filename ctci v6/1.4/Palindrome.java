public class Palindrome {

  public static boolean palindrome = false;
  public static boolean palindromeCheck(String a) {
    char[] word = a.toLowerCase().toCharArray();
    int i1 = 0;
    int i2 = word.length - 1;
    while (i2 > i1) {
        if (word[i1] != word[i2]) {
            return false;
        }
        ++i1;
        --i2;
    }
    return true;
  }

  public static boolean permute(String prefix, String remainingString) {
    if(palindrome)
      return palindrome;
    int length = remainingString.length();
    if(length == 0) {
      palindrome = palindromeCheck(prefix);
    }
    for(int i=0;i<length;i++) {
      permute(prefix+remainingString.charAt(i),remainingString.substring(0,i)+remainingString.substring(i+1,length));
    }
    return palindrome;
  }
  public static boolean permutations(String a) {
    palindrome = false;
    return permute("",a);
  }
  public static void main(String[] args) {
    System.out.println(permutations("Tact Coa"));
    System.out.println(permutations("TacoCat"));
    System.out.println(permutations("abcab"));
    System.out.println(permutations("Tact Coa"));
  }
}
