import java.util.Scanner;

public class BOJ_2577
{
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		long multi = 1;
		int[] arr = new int[10];
		
		for(int i=0;i<3;i++) {
			long num = sc.nextLong();
			multi *= num;
		}
		
		String str = Long.toString(multi);
		
		for(int i=0;i<str.length();i++) {
			arr[str.charAt(i)-'0']++;
		}
		
		for(int i=0;i<10;i++) {
			System.out.println(arr[i]);
		}
		
		
	}
}
