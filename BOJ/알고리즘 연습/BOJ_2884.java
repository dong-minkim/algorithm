package Study;

import java.util.Scanner;

public class BOJ_2884 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int x = scan.nextInt();
		int y = scan.nextInt();
		
		if(x==0 && y<45) {
			x=23;
			y+=15;
		}
		else if(y<45) {
			x-=1;
			y+=15;
		}
		else {
			y-=45;
		}
		
		System.out.println(x+" "+y);
		
	}
}
