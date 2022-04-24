import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ_1018 {

	static char[][] chess;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		chess = new char[n+1][m+1];
		
		for(int i=0;i<n;i++) {
			String str = br.readLine();
			for(int j=0;j<m;j++) {
				chess[i][j]=str.charAt(j);
			}
		}
		
		int min=5000;
		for(int i=0;i<=n-8;i++) {
			for(int j=0;j<=m-8;j++) {
				if(min>solution(i,j,true)) min=solution(i,j,true);
				if(min>solution(i,j,false)) min=solution(i,j,false);
			}
		}
		
		System.out.println(min);
	}
	
	static public int solution(int y, int x, boolean color) {
		int cnt=0;
		boolean flag = color;
		
		char tmp;
		
		for(int i=y;i<y+8;i++) {
			flag=!flag;
			for(int j=x;j<x+8;j++) {
				
				if(flag==true) tmp='W';
				else tmp='B';
				
				if(chess[i][j]!=tmp) cnt++;
				flag = !flag;
			}
		}
		
		return cnt;
	}
}


