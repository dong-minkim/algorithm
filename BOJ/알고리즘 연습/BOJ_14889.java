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

public class BOJ_14889 {
	
	static int[][] map;
	static boolean[] visited;
	static int n;
	static int min = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		StringTokenizer st;
		
		map = new int[n+1][n+1];
		visited = new boolean[n+1];
		
		for(int i=1;i<=n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1;j<=n;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		solution(0,1);
		System.out.println(min);
		
	}
	
	static void solution(int cnt, int index) {
		if(cnt==n/2) {
			cal();
			return;
		}
		
		for(int i=index;i<=n;i++) {
			if(visited[i] == false) {
				visited[i] = true;
				solution(cnt+1, i+1);
				visited[i] = false;
			}
		}
	}
	
	static void cal() {
		int teamScore=0;
		int linkScore=0;
		
		for(int i=1;i<=n-1;i++) {
			for(int j=i+1;j<=n;j++) {
				
				if(visited[i]==true && visited[j]==true) {
					teamScore += (map[i][j]+map[j][i]);
				}
				
				else if(visited[i]==false && visited[j]==false ) {
					linkScore += (map[i][j]+map[j][i]);
				}
			}
		}
		min = Math.min((int)Math.abs(teamScore - linkScore), min);
		if(min==0) {
			System.out.println(min);
			System.exit(0);
		}
	}
}
