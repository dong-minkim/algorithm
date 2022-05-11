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

public class BOJ_2580 {
	
	static Vector<pair<Integer,Integer>> v = new Vector<pair<Integer,Integer>>();
	static int[][] arr = new int[9][9];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st; 
		
		for(int i=0;i<9;i++) {
			st = new StringTokenizer(br.readLine()); 
			for(int j=0;j<9;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j] == 0) v.add(new pair<>(i,j));
				
			}
		}
		solution(0);
	}
	
	static void solution(int n) {
		if(n == v.size()) {
			StringBuilder sb = new StringBuilder();
			for(int i=0;i<9;i++) {
				for(int j=0;j<9;j++) {
					sb.append(arr[i][j]).append(" ");
				}
				sb.append("\n");
				
			}
			System.out.println(sb);
			System.exit(0);
		}
		
		int row = v.get(n).first;
		int col = v.get(n).second;
		for(int i=1;i<=9;i++) {
			if(check(row,col,i)==true){
				arr[row][col]=i;
				solution(n+1);
			}
		}
		arr[row][col] = 0;
	}
	
	static boolean check(int row, int col, int num) {
		for(int i=0;i<9;i++) {
			if(arr[row][i] == num || arr[i][col] == num) return false;
		}	
		
		int y = (row/3) * 3;
		int x = (col/3) * 3;
			
		for(int i=y;i<y+3;i++) {
			for(int j=x;j<x+3;j++) {
				if(arr[i][j] == num) return false;
			}
		}
		
		return true;
	}

	static class pair<L,R>{
		L first;
		R second;
		pair(L first,R second){
			this.first = first;
			this.second = second;
		}
		
		public void setFirst(L first) { this.first = first;}
		public void setSecond(R second) {this.second = second;}
	}
}
