public class Permutation {

  public static boolean permutationCheck(String a, String b) {
    int[] array = new int[128];
    if (a.length() != b.length())
      return false;
    for (int i=0;i<a.length();i++) {
      array[a.charAt(i)]++;
    }
    for (int i=0;i<b.length();i++) {
      array[b.charAt(i)]--;
      if (array[b.charAt(i)] < 0) {
		    	return false;
		    }
    }
    return true;
  }
  public static void main(String[] args) {

    System.out.println(permutationCheck("hello","hlloe"));
    System.out.println(permutationCheck("abcde","abcdef"));
    System.out.println(permutationCheck("abcde","abcdg"));
  }
}
