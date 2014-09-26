public class Sum{

	public static void main(String args[]){
		LinkedList l1 = new LinkedList();
		LinkedList l2 = new LinkedList();
		LinkedList ll = new LinkedList();
		l1.addAtEnd(7);
		l1.addAtEnd(1);
		l1.addAtEnd(6);
		
		l2.addAtEnd(5);
		l2.addAtEnd(9);
		l2.addAtEnd(2);
		
		System.out.println("Addition operation");
		ll.add(l1.getHead(),l2.getHead());
		ll.print();
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
	
	// Assuming both numbers have same length
	public void add(Node n1, Node n2){
		// carry over
		int temp=0;
		while(n1!=null && n2!=null){
			temp += n1.getValue() + n2.getValue();
			this.addAtEnd(temp%10);
			temp /= 10;
			n1 = n1.getNext();
			n2 = n2.getNext();
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