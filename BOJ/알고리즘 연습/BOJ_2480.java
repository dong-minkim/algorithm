import java.util.Scanner;

public class BOJ_2480 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		
		if(a==b && a==c && b==c) {
			System.out.println(a*1000 + 10000);
		}
		else if(a==b || a==c) {
			System.out.println(a*100 + 1000);
		}
		else if(b==c) {
			System.out.println(b*100+1000);
		}
		else {
			System.out.println(100 * Math.max(a, Math.max(b, c)));
		}
	}

}
