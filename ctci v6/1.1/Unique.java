public class Unique {

  public static boolean uniqueCheck(String unique) {
    boolean[] array = new boolean[128];
    for (int i=0;i<unique.length();i++) {
      if(array[unique.charAt(i)])
        return false;
      else
        array[unique.charAt(i)] = true;
    }
    return true;
  }
  public static void main(String[] args) {

    System.out.println(uniqueCheck("hello"));
    System.out.println(uniqueCheck("abcde"));
  }
}
