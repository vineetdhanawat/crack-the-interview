import java.util.LinkedList;

public class DogCat{
	public static void main(String[] args){
		AnimalQueue animals = new AnimalQueue();
		animals.enqueue(new Cat("Callie"));
		animals.enqueue(new Cat("Kiki"));
		animals.enqueue(new Dog("Fido"));
		animals.enqueue(new Dog("Dora"));
		animals.enqueue(new Cat("Kari"));
		animals.enqueue(new Dog("Dexter"));
		animals.enqueue(new Dog("Dobo"));
		animals.enqueue(new Cat("Copa"));
		
		System.out.println(animals.dequeueAny().getName());	
		System.out.println(animals.dequeueAny().getName());	
		System.out.println(animals.dequeueAny().getName());	
		
		animals.enqueue(new Dog("Dapa"));
		animals.enqueue(new Cat("Kilo"));
		System.out.println(animals.dequeueCat().getName());
		System.out.println(animals.dequeueDog().getName());
		
		while (animals.size() != 0) {
			System.out.println(animals.dequeueAny().getName());	
		}
		
		
	}
}

class Animal{
	private String name;
	private int order;
	public Animal(String name){
		this.name = name;
	}
	
	public String getName(){
		return name;
	}
	
	public int getOrder(){
		return order;
	}
	
	public void setOrder(int order){
		this.order = order;
	}
}

class Dog extends Animal{
	public Dog(String name){
		super(name);
	}
}

class Cat extends Animal{
	public Cat(String name){
		super(name);
	}
}

class AnimalQueue{
	LinkedList<Dog> dogs = new LinkedList<Dog>();
	LinkedList<Cat> cats = new LinkedList<Cat>();
	int order=0;
	public void enqueue(Animal a){
		a.setOrder(order);
		order++;
		if(a instanceof Dog){
			dogs.addLast((Dog)a);
		}
		else if(a instanceof Cat){
			cats.addLast((Cat)a);
		}
	}
	
	public Animal dequeueAny(){
		if(dogs.size()>0 && cats.size()>0){
			if(dogs.peek().getOrder() < cats.peek().getOrder())
				return dogs.poll();
			else
				return cats.poll();
		}
		else if(dogs.size()==0 && cats.size()>0){
			return cats.poll();
		}
		else if(cats.size()==0 && dogs.size()>0){
			return dogs.poll();
		}
		return null;
	}
	
	public Animal dequeueDog(){
		if(dogs.size()>0){
			return dogs.poll();
		}
		else return null;
	}
	
	public Animal dequeueCat(){
		if(cats.size()>0){
			return cats.poll();
		}
		else return null;
	}

	public int size(){
		return dogs.size() + cats.size();
	}
}