import java.util.Stack;
import java.util.ArrayList;

public class QueueStack{
	public static void main(String[] args){
		MyQueue myqueue = new MyQueue();
		
		for(int i=0;i<10;i++)
			myqueue.enqueue(i);
		
		for(int i=0;i<10;i++)
			System.out.println(myqueue.dequeue());
	}
}

class MyQueue{
	Stack<Integer> first = new Stack<Integer>();
	Stack<Integer> second = new Stack<Integer>();

	public void enqueue(int value) {
        first.push(value);
    }
	
	public int dequeue() {
        if(second.isEmpty()){
			while(!first.isEmpty()){
				second.push(first.pop());
			}
		}
		return second.pop();
    }
}