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

public class BOJ_11053 {
	
	static int dp[];
	static int num[];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		
		num = new int[n];
		dp = new int[n];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			num[i] = Integer.parseInt(st.nextToken());
			dp[i]=1;
		}
		int result = 1;
		for(int i=0;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				if(num[i]<num[j]) {
					dp[j] = Math.max(dp[i] + 1, dp[j]);
					result = Math.max(result, dp[j]);
				}
			}
		}
		
		System.out.println(result);
	}
}
