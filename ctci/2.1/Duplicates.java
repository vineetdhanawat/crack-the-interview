import java.util.HashMap;

public class Duplicates{

	public static void main(String args[]){
		LinkedList ll = new LinkedList();
		ll.addAtEnd(4);
		ll.addAtEnd(5);
		ll.addAtEnd(6);
		ll.addAtEnd(4);
		ll.addAtEnd(7);
		ll.print();
		System.out.println("After removing duplicates");
		ll.removeDuplicates();
		ll.print();
	}
}

class LinkedList{
	private Node head;
	HashMap<Object,Boolean> HM = new HashMap<Object,Boolean>();
	public LinkedList(){
		head = null;
	}
	
	// Assuming there are atleast 2 nodes to check duplicates
	public void removeDuplicates(){
		Node prev = head;
		Node current = head;
		Boolean exist;
		do{
			exist = HM.get(current.getValue());
			if(exist!=null && exist){
				prev.setNext(current.getNext());
			}
			else {
				HM.put(current.getValue(),true);
				prev = current;
			}
			current = current.getNext();
		}
		while(current.getNext()!=null);
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
	private Object value;
	
	public Node(Object value){
		this.value = value;
	}
	
	public Node getNext(){
		return next;
	}
	
	public void setNext(Node nextNode){
		next = nextNode;
	}
	
	public Object getValue(){
		return value;
	}
}