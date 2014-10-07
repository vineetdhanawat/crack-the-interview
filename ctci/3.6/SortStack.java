import java.util.Stack;
import java.util.ArrayList;

public class SortStack{
	public static void main(String[] args){
		Stack<Integer> s = new Stack<Integer>();
		s.push(1);
		s.push(3);
		s.push(6);
		s.push(5);
		s.push(4);
		s.push(2);
		
		s = sort(s);
		
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
	}
	
	public static Stack<Integer> sort(Stack<Integer> s){
		Stack<Integer> temp = new Stack<Integer>();
		while(!s.isEmpty()){
			int value = s.pop();
			while(!temp.isEmpty() && temp.peek()>value){
				s.push(temp.pop());
			}
			temp.push(value);
		}
		return temp;
	}
}