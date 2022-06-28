import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Solution{
	
	static long[][] cost;
	static int n,m;
	
	static void Floyd() {
		for(int k=1;k<=n;k++) {
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					if(cost[i][j]>=cost[i][k]+cost[k][j])
						cost[i][j]=cost[i][k]+cost[k][j];
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		cost = new long[n+1][n+1];
		
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				cost[i][j] = Integer.MAX_VALUE;
			}
		}
		
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			cost[u][v] = w;
		}
		
		
		Floyd();
		
		int answer = Integer.MAX_VALUE;
		for(int i=1;i<=n;i++) {
			if(answer>cost[i][i]) answer=(int)cost[i][i];
		}
		if(answer==Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(answer);
	}
}