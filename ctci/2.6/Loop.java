public class Loop{

	public static void main(String args[]){
		LinkedList ll = new LinkedList();
		ll.addAtEnd(1);
		ll.addAtEnd(2);
		ll.addAtEnd(3);
		ll.addAtEnd(4);
		ll.addAtEnd(5);
		ll.createLoop();
		
		
		ll.breakLoop();
		//ll.print();
	}
}

class LinkedList{
	private Node head;
	public LinkedList(){
		head = null;
	}
	
	public Node getHead(){
		return head;
	}
	
	public void createLoop(){
		Node current=head;
		while(current.getNext()!=null){
			current = current.getNext();
		}
		current.setNext(head.getNext().getNext());
	}

	public void breakLoop(){
		Node slow = head;
		Node fast = head.getNext();
		while(fast!=null && fast.getNext()!=null){
			if(slow == fast){
				System.out.println("Loop detection at "+slow.getValue());
				break;
			}
			else {
				slow = slow.getNext();
				fast = fast.getNext().getNext();
			}
		}
	}

	public void addAtEnd(int value){
		Node current = head;
		if(current == null){
			head = new Node(value);
		}
		else {
			while(current.getNext()!=null){
				current = current.getNext();
			}
			Node temp = new Node(value);
			current.setNext(temp);
		}
	}
	
	public void print(){
		Node current = head;
		while(current.getNext()!=null){
			System.out.println(current.getValue());
			current = current.getNext();
		}
		System.out.println(current.getValue());
	}
}

class Node{
	private Node next;
	private int value;
	
	public Node(int value){
		this.value = value;
	}
	
	public Node getNext(){
		return next;
	}
	
	public void setNext(Node nextNode){
		next = nextNode;
	}
	
	public int getValue(){
		return value;
	}
	
	public void setValue(int value){
		this.value = value;
	}
}