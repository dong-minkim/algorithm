import java.util.Scanner;

public class BOJ_2562
{
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int max=0;
		int order=0;
		
		for(int i=0;i<9;i++) {
			int n=sc.nextInt();
			if(max<n) {
				max = n;
				order=i+1;
			}
		}
		
		System.out.println(max);
		System.out.println(order);
		
	}
}
