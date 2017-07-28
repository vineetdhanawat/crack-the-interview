public class OneAway {

  public static boolean checkReplace(String a, String b) {
    int counter=0;
    for(int i=0;i<a.length();i++) {
      if(a.charAt(i) != b.charAt(i))
        counter++;
    }
    if(counter == 1)
      return true;
    return false;
  }

  // same as checkRemove
  // a is longer
  public static boolean checkInsert(String a, String b) {
    int length1 = 0;
    int length2 = 0;
    while(length1<a.length() && length2<b.length()) {
      if(a.charAt(length1) != b.charAt(length2)){
        if(length1 != length2)
          return false;
        length1++;
      } else {
        length1++;length2++;
      }
    }
    return true;
  }

  public static boolean checkOneAway(String a, String b) {
    if(a.length()-b.length() == 0) {
      return checkReplace(a,b);
    }
    if(a.length()-b.length() == 1) {
      return checkInsert(a,b);
    }
    if(a.length()-b.length() == -1) {
      return checkInsert(b,a);
    }
    return false;
  }

  public static void main(String[] args) {
    System.out.println(checkOneAway("pale","ple"));
    System.out.println(checkOneAway("pales","pale"));
    System.out.println(checkOneAway("pale","bale"));
    System.out.println(checkOneAway("pale","bake"));
  }
}
