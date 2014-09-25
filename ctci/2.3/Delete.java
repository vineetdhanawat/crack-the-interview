public class Delete{

	public static void main(String args[]){
		LinkedList ll = new LinkedList();
		ll.addAtEnd(4);
		ll.addAtEnd(5);
		ll.addAtEnd(6);
		ll.addAtEnd(7);
		ll.addAtEnd(8);
		ll.addAtEnd(9);
		ll.addAtEnd(10);
		ll.print();
		System.out.println("Deleting 5 with direct access to that node");
		ll.delete(ll.returnHead().getNext());
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
	
	public boolean delete(Node n){
		if(n!=null && n.getNext()!=null){
			n.setValue(n.getNext().getValue());
			n.setNext(n.getNext().getNext());
			return true;
		}
		else
			return false;
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