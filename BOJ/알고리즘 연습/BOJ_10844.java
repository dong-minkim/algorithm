import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class BOJ_10844 {
	
	static long dp[][];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		
		if(n==1) {
			System.out.println(9);
		    System.exit(0);
		}
		
		dp = new long[n+1][10];
		
		for(int i=1;i<=9;i++) dp[1][i]=1;
		for(int i=2;i<=n;i++) {
			for(int j=0;j<=9;j++) {
				if(j==0) dp[i][j] = dp[i-1][j+1] % 1000000000;
				else if(j==9) dp[i][j] = dp[i-1][j-1] % 1000000000;
				else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
			}
		}
		
		long result = 0;
		for(int i=0;i<10;i++) {
			result += dp[n][i];
		}
		
		System.out.println(result % 1000000000);
		
		
	}
}
