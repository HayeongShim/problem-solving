import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static ArrayList<Integer> list = new ArrayList<Integer>();
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		for (int i = 0; i < N; i++) {
			String str = sc.next();
			if (str.equals("push")) push(sc.nextInt());
			else if (str.equals("pop")) System.out.println(pop());
			else if (str.equals("size")) System.out.println(size());
			else if (str.equals("empty")) System.out.println(empty());
			else if (str.equals("top")) System.out.println(top());
		}
	
	}
	
	public static void push(int n) {
		list.add(n);
	}
	
	public static int pop() {
		if (list.isEmpty()) return -1;
		else return list.remove(list.size() - 1);
	}
	
	public static int size() {
		return list.size();
	}
	
	public static int empty() {
		if (list.isEmpty()) return 1;
		else return 0;
	}
	
	public static int top() {
		if (list.isEmpty()) return -1;
		else return list.get(list.size() - 1);
	}
}