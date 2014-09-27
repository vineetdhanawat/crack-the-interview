public class Palindrome{

	public static void main(String args[]){
		LinkedList ll = new LinkedList();
		ll.addAtEnd(1);
		ll.addAtEnd(2);
		ll.addAtEnd(3);
		ll.addAtEnd(3);
		ll.addAtEnd(2);
		ll.addAtEnd(1);
		//ll.addAtEnd(1);
		ll.palindromeCheck();
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

	public void palindromeCheck(){
		Node slow=head;
		Node fast=head;
		Node prevtoslow=null;
		Node secondhalf;
		Node mid;
		
		if(head!=null && head.getNext()!=null){
			while(fast!=null && fast.getNext()!=null){
				fast = fast.getNext().getNext();
				prevtoslow = slow;
				slow = slow.getNext();
			}
			
			// odd numbers of elements
			if(fast!=null){
				mid = slow;
				slow = slow.getNext();
			}
			
			secondhalf = slow;
			prevtoslow.setNext(null);
			secondhalf = reverse(secondhalf);
			//this.print(head);
			//System.out.println("----------");
			//this.print(secondhalf);
			System.out.println(compare(head,secondhalf));
		}
	}

	public boolean compare(Node first, Node second){
		while(first!=null && second!=null){
			if(first.getValue()!=second.getValue()){
				return false;
			}
			first = first.getNext();
			second = second.getNext();
		}
		return true;
	}
	
	public Node reverse(Node current){
		Node next=null;
		Node prev=null;
		while(current!=null){
			next = current.getNext();
			current.setNext(prev);
			prev = current;
			current = next;
		}
		current = prev;
		return current;
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
	
	public void print(Node current){
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