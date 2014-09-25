public class KLast{

	public static void main(String args[]){
		LinkedList ll = new LinkedList();
		ll.addAtEnd(4);
		ll.addAtEnd(5);
		ll.addAtEnd(6);
		ll.addAtEnd(7);
		ll.addAtEnd(8);
		ll.addAtEnd(9);
		ll.addAtEnd(10);
		ll.addAtEnd(11);
		ll.print();
		System.out.println("Kth/2nd Element from Last");
		ll.printkLast(2);

	}
}

class LinkedList{
	private Node head;
	public LinkedList(){
		head = null;
	}
	
	// Assuming k is less than total number of elements
	public void printkLast(int k){
		Node first = head;
		Node second = head;
		for(int i=1;i<k;i++)
		first = first.getNext();
		while(first.getNext()!=null){
			first = first.getNext();
			second = second.getNext();
		}
		System.out.println(second.getValue());
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
}