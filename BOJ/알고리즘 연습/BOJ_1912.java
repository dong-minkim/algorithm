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

public class BOJ_1912 {
	
	static int dp[];
	static int num[];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		num = new int[n+1];
		dp = new int[n+1];
		
		for(int i=1;i<=n;i++) {
			 num[i] = Integer.parseInt(st.nextToken());
			 dp[i] = num[i];
		}
		
		int result = Integer.MIN_VALUE;
		
		for(int j=1;j<=n;j++) {
				dp[j] = Math.max(dp[j], dp[j-1] + dp[j]);
				result = Math.max(result, dp[j]);
		}
		
		System.out.println(result);
	}
}
