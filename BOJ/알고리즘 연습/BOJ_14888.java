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

public class BOJ_14888 {
	
	static int[] num;
	static int[] op = new int[4];
	static int n;
	static int max = Integer.MIN_VALUE;
	static int min = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		num = new int[n];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			num[i] = Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<4;i++) {
			op[i] = Integer.parseInt(st.nextToken());
		}
		
		solution(num[0],0);
		
		StringBuilder sb = new StringBuilder();
		sb.append(max).append("\n").append(min);
		System.out.println(sb);
	}
	
	static void solution(int result,int cnt) {
		
		if(cnt==n-1) {
			max = Math.max(result, max);
			min = Math.min(result, min);
			return;
		}
		
		for(int i=0;i<4;i++) {
			if(op[i]>0) {
				op[i]--;
				
				if(i==0) solution(result+num[cnt+1], cnt+1);
				if(i==1) solution(result-num[cnt+1], cnt+1);
				if(i==2) solution(result*num[cnt+1], cnt+1);
				if(i==3) solution(result/num[cnt+1], cnt+1);
				
				op[i]++;
			}
		}
	}
	
	
}
