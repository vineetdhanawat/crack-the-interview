public class Partition{

	public static void main(String args[]){
		LinkedList ll = new LinkedList();
		ll.addAtEnd(8);
		ll.addAtEnd(9);
		ll.addAtEnd(10);
		ll.addAtEnd(4);
		ll.addAtEnd(5);
		ll.addAtEnd(6);
		ll.addAtEnd(7);
		ll.addAtEnd(11);
		ll.print();
		System.out.println("Partition list around x=7");
		ll.partition(7);
		ll.print();
	}
}

class LinkedList{
	private Node head;
	public LinkedList(){
		head = null;
	}
	
	public Node returnHead(){
		return head;
	}
	
	public void partition(int x){
		Node leftstart = null;
		Node leftend = null;
		Node rightstart = null;
		Node rightend = null;
		Node current = head;
		while(current!=null){
			if(current.getValue() < x){
				if(leftstart == null){
					leftstart = current;
					leftend = current;
				}
				else {
					leftend.setNext(current);
					leftend = leftend.getNext();
				}
			}
			else {
				if(rightstart == null){
					rightstart = current;
					rightend = current;
				}
				else {
					rightend.setNext(current);
					rightend = rightend.getNext();
				}
			}
			current = current.getNext();
		}
		leftend.setNext(null);
		rightend.setNext(null);
		if(leftstart == null)
			head = rightstart;
		if(rightstart == null)
			head = leftstart;
		if(leftstart!=null && rightstart!=null){
			leftend.setNext(rightstart);
			head = leftstart;
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