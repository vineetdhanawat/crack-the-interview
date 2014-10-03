public class Stack{
	
	static int stackSize = 10;
	static int[] array = new int[stackSize*3];
	static int[] stackPointer = {0,0,0};
	public static void main(String args[]){
		push(0,2);
		push(0,1);
		push(0,4);
		push(0,5);

		push(1,2);		
		push(1,1);
		push(1,4);
		push(1,5);

		push(2,2);
		push(2,1);
		push(2,4);
		push(2,5);
		
		pop(2);
		pop(2);
		pop(2);
		pop(2);
		pop(2);
	}
	
	public static boolean push(int stackNumber, int number){
		if(stackPointer[stackNumber] >= 10){
			return false;
		}
		array[stackNumber*stackSize + stackPointer[stackNumber]] = number;
		stackPointer[stackNumber]++;
		return true;
	}
	
	public static boolean pop(int stackNumber){
		if(stackPointer[stackNumber] <= 0){
			return false;
		}
		System.out.println(array[stackNumber*stackSize + stackPointer[stackNumber] - 1]);
		stackPointer[stackNumber]--;
		return true;
	}
}