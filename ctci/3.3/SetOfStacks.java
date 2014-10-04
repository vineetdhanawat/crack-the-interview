import java.util.Stack;
import java.util.ArrayList;

public class SetOfStacks{
	
	public static void main(String[] args){
		int capacity = 3;
		StackDS ds = new StackDS(capacity);

		for(int i=0;i<11;i++){
			ds.push(i);
		}
		System.out.println("Popped:" + ds.popAt(2));

		for(int i=0;i<10;i++){
			System.out.println("Popped:" + ds.pop());
		}
	}
}

class StackDS{
	int capacity;
    ArrayList<Stack<Integer>> stacks = new ArrayList<Stack<Integer>>();

    public StackDS(int capacity){
		this.capacity = capacity;  
    }
	
	public Stack getLastStack(){
		if (stacks.size() == 0){
			return null;
		}
		return stacks.get(stacks.size()-1);
	}

    void push(int value){
		Stack last = getLastStack();
        if(last!=null && last.size()<capacity){
            last.push(value);
        }
        else{
			last = new Stack<Integer>();
			last.push(value);
			stacks.add(last);
		}
    }

    int popAt(int index){
		Stack<Integer> last = stacks.get(index);
		int value = last.pop();
        if (last.size() == 0) {
            stacks.remove(stacks.size() - 1);         
        }
        return value;
    }

    int pop(){
		Stack<Integer> last = getLastStack();
		int value = last.pop();
        if (last.size() == 0) {
            stacks.remove(stacks.size() - 1);         
        }
        return value;
    }
}