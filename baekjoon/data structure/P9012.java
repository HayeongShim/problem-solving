import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static ArrayList<Integer> list = new ArrayList<Integer>();
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		for (int i = 0; i < N; i++) {
			String str = sc.next();
			func(str);
			list = new ArrayList<Integer>();
		}
	}
	
	public static void func(String str) {
		for (int j = 0; j < str.length(); j++) {
			if (str.charAt(j) == '(') push(1);
			else if (str.charAt(j) == ')') {
				int temp = pop();
				if (temp == -1) {	//empty
					System.out.println("NO");
					return;
				}
			}
		}
		int temp = pop();
		if (temp != -1) {
			System.out.println("NO");
			return;
		}
		else if (temp == -1) {	//empty
			System.out.println("YES");
			return;
		}
	}
	
	public static void push(int n) {
		list.add(n);
	}
	
	public static int pop() {
		if (list.isEmpty()) return -1;
		else return list.remove(list.size() - 1);
	}
}