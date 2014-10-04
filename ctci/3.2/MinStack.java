import java.util.Stack;

public class MinStack{
	public static void main(String[] args){
		StackDS ts = new StackDS();
		ts.push(3);
		ts.push(5);
		ts.push(2);
		ts.push(1);
		System.out.println(ts.min());
		System.out.println(ts.pops());
		System.out.println(ts.min());
		System.out.println(ts.pops());
		System.out.println(ts.min());
	}
}

class StackDS extends Stack<Integer>{

    Stack<Integer> minStack;

    public StackDS(){
        minStack = new Stack<Integer>();    
    }

    void push(int value){
        if (value <= min()) {
            minStack.push(value);
        }
        super.push(value);
    }

    int pops(){
        int value = super.pop();
        if (value == min()) {
            minStack.pop();         
        }
        return value;
    }

    int min(){
        if (minStack.isEmpty()) {
            return Integer.MAX_VALUE;
        } else {
            return minStack.peek();
        }
    }
}