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

public class BOJ_1010 {
	
	static int[][] dp = new int[30][30];
	
	public static void main(String[] args) throws IOException {
	
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		
		int tc = Integer.parseInt(br.readLine());
		while(tc-->0) {
			
			st = new StringTokenizer(br.readLine(), " ");
			
			int a = Integer.parseInt(st.nextToken());	
			int b = Integer.parseInt(st.nextToken());	
			
			sb.append(solution(b,a)).append('\n');
		}
		
		System.out.println(sb);
		
	}
	
	public static int solution(int a, int b) {
		
		if(dp[a][b]>0) return dp[a][b];
		if(a==b|b==0) return dp[a][b]=1;
		return dp[a][b] = solution(a-1,b-1) + solution(a-1,b);
	}
}


