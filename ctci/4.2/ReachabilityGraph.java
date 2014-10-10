import java.util.LinkedList;
import java.util.Stack;

public class ReachabilityGraph{
	public static void main(String[] args){
		Graph g = new Graph();
		Node[] temp = new Node[6];

		temp[0] = new Node("a", 3);
		temp[1] = new Node("b", 0);
		temp[2] = new Node("c", 0);
		temp[3] = new Node("d", 1);
		temp[4] = new Node("e", 1);
		temp[5] = new Node("f", 0);

		temp[0].addAdjacent(temp[1]);
		temp[0].addAdjacent(temp[2]);
		temp[0].addAdjacent(temp[3]);
		temp[3].addAdjacent(temp[4]);
		temp[4].addAdjacent(temp[5]);
		for (int i = 0; i < 6; i++) {
			g.addNode(temp[i]);
		}

		Node[] n = g.getNodes();

		System.out.println("Graph: a->b,a->c,a->d,d->e,e->f");
		// finding path from start node to end
		System.out.println("BFS Implementation");
		System.out.println("a to f:"+findPathBFS(g, n[0], n[5]));
		System.out.println("b to f:"+findPathBFS(g, n[1], n[5]));

		System.out.println("DFS Implementation");
		System.out.println("a to f:"+findPathDFS(g, n[0], n[5]));
		System.out.println("b to f:"+findPathDFS(g, n[1], n[5]));
	}

	public static boolean findPathBFS(Graph g, Node start, Node end) {
		// BFS requires queue implementation
		LinkedList<Node> q = new LinkedList<Node>();
		// for new path computation
		for (Node n : g.getNodes()) {
		  n.visited = false;
		}

		q.add(start);
		Node n;
		while(!q.isEmpty()) {
		  n = q.removeFirst();
		  for (Node current : n.getAdjacent()) {
			if (current.visited == false) {
				if (current == end) {
					return true;
				} else {
					current.visited = true;
					q.add(current);
				}
			}
			}
		}
		return false;
	}

	public static boolean findPathDFS(Graph g, Node start, Node end) {
		// DFS requires queue implementation
		Stack<Node> s = new Stack<Node>();
		// for new path computation
		for (Node n : g.getNodes()) {
			n.visited = false;
		}

		s.add(start);
		Node n;
		while(!s.isEmpty()) {
			n = s.pop();
			for (Node current : n.getAdjacent()) {
				if (current.visited == false) {
					if (current == end) {
						return true;
					} else {
						current.visited = true;
						s.push(current);
					}
				}
			}
		}
		return false;
	}
}

class Node {
	private Node adjacent[];
	public int adjacentCount;
	private String vertex;
	public boolean visited=false;

	// adjacentLength = 0 for directed graph
	public Node(String vertex, int adjacentLength) {
		this.vertex = vertex;
		adjacentCount = 0;
		adjacent = new Node[adjacentLength];
	}

	public void addAdjacent(Node x) {
		this.adjacent[adjacentCount] = x;
		adjacentCount++;
	}
	public Node[] getAdjacent() {
		return adjacent;
	}
}

class Graph {
	private Node[] vertices;
	private int count=0;
	public Graph() {
		vertices = new Node[6];
    }

    public void addNode(Node x) {
			vertices[count] = x;
			count++;
    }

    public Node[] getNodes() {
        return vertices;
    }
}