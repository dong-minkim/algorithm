import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Solution{
	
	static class Node{
		int v,time;
		public Node(int v, int time) {
			this.v = v;
			this.time = time;
		}
	}
	
	static ArrayList<Node>[] graph;
	static long[] time;
	static int N,M;
	static boolean cycle = false;
	
	static void Bellman() {
		time[1] = 0;
		for(int k=1;k<=N;k++) {       //정점이 N개라고 할때, 출발 정점에서 도착 정점까지 최단경로
			for(int i=1;i<=N;i++) {  //가는 edge의 최대 개수는 n-1개이기 때문에
				for(int j=0;j<graph[i].size();j++) { 
					int next = graph[i].get(j).v;
					int nextTime = graph[i].get(j).time;
					if(time[i] == Long.MAX_VALUE) continue;
					if(time[next] > time[i] + nextTime) {
						time[next] = time[i] + nextTime;
						if(k==N)
							cycle = true;
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		graph = new ArrayList[N+1];
		time = new long[N+1];
		
		for(int i=1;i<=N;i++) {
			graph[i] = new ArrayList<Node>();
			time[i] = Long.MAX_VALUE;
		}
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			graph[u].add(new Node(v,w));
		}
		
		Bellman();
		
		StringBuilder sb = new StringBuilder();
		if(cycle) sb.append(-1).append('\n');
		else {
			for(int i=2;i<=N;i++) {
				if(time[i]==Long.MAX_VALUE) sb.append(-1).append('\n');
				else sb.append(time[i]).append('\n');
			}
		}
		System.out.println(sb);
		
	}
}