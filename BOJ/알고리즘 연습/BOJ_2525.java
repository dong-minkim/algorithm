package Study;

import java.util.Scanner;

public class BOJ_2525 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int hour = scan.nextInt();
		int minute = scan.nextInt();
		
		int time = scan.nextInt();
		
		int tmp = (time+minute)/60;
		
		System.out.println((hour+tmp)%24 + " " + (time+minute)%60);
		
	}
}
