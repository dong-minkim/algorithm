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

public class BOJ_9663 {
	
	static int n;
	static int[][] chess;
	static int cnt=0;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		for(int i=0;i<n;i++) {
			chess = new int[n][n];
			chess[0][i] = 1;
			solution(chess, 1);
		}
		
		System.out.println(cnt);
	}
	
	static void solution(int[][] chess, int row) {
		if(row == n) {
			cnt++;
			return;
		}
		
		for(int i=0;i<n;i++) {
			if(check(chess,row,i)) {
				chess[row][i] = 1;
				solution(chess, row+1);
				chess[row][i] = 0;
			}
		}
	}
	
	static boolean check(int[][] chess, int row, int col) {
		for(int i=0;i<row;i++) {
			if(chess[i][col] == 1) return false;
		}
		
		int ty = row - 1;
		int tx = col - 1;
		while(ty>=0 && tx>=0) {
			if(chess[ty--][tx--]==1) return false;
		}
		
		
		ty =row-1;
		tx =col+1;
		while(ty>=0 && tx<n) {
			if(chess[ty--][tx++]==1) return false;
		}
		
		
		return true;
	}
}
