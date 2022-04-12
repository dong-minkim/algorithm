import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class BOJ_2775 {
	
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner(System.in);
		
		int testCase = scan.nextInt();
		
		while(testCase-->0) {
			long sum = 0;
			
			int k = scan.nextInt();
			int n = scan.nextInt();
			
			int[][] arr = new int[k+1][n+1];
			
			for(int i=0;i<=k;i++) {
				arr[i][1]=1;
			}
			
			for(int j=1;j<=n;j++) {
				arr[0][j]=j;
			}
			
			for(int i=1;i<=k;i++) {
				for(int j=2;j<=n;j++) {
					arr[i][j]=arr[i-1][j]+arr[i][j-1];
				}
			}
			System.out.println(arr[k][n]);
			
			
		}
		
	}
	
}
