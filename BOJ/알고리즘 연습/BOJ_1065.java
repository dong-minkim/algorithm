import java.util.Scanner;

class Hansu {
	int result(int num) {
		if(num<100) {
			return num;
		}
		else {
			int cnt = 99;
			if(num==1000) num=999;
			for(int i=100;i<=num;i++) {
				int num1 = i/100;
				int num2 = (i%100)/10;
				int num3 = i%10;
			
				if(num1-num2 == num2-num3) {
					cnt++;
				}
			
			}
			
			return cnt;
		}
	}
}

public class BOJ_1065{
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		int num = scan.nextInt();
		
		System.out.println(new Hansu().result(num));
		
		
		
	}
	
}
