import java.util.Stack;
import java.util.ArrayList;

public class Hanoi{
	static int towers = 3;
	static ArrayList<Stack<Integer>> stacks = new ArrayList<Stack<Integer>>();
	public static void main(String[] args){

		for(int i=0;i<towers;i++){
			stacks.add(new Stack<Integer>());
		}
		for(int i=0;i<3;i++){
			stacks.get(0).push(i);
		}

		move(3,0,1,2);
		
		for(int i=0;i<3;i++){
			System.out.println(stacks.get(1).pop());
		}
	}
	
	public static void move(int n, int stacka, int stackb, int stackc){
		if(n>0){
			System.out.println("move " + n + " disks from " + stacka + " to " + stackb);
			move(n-1,stacka,stackc,stackb);
			int value = stacks.get(stacka).pop();
			stacks.get(stackb).push(value);
			move(n-1,stackc,stackb,stacka);
		}
	}
}