import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Solution {
	
	static class Node implements Comparable<Node>{
		int v, cost;
		public Node(int v, int cost) {
			this.v=v;
			this.cost=cost;
		}
		
		@Override
		public int compareTo(Node o) {
			return this.cost - o.cost;
		}
		
	}
	static ArrayList<Node>[] graph;
	static int[] dist;
	
	static void dijkstra(int start) {
		dist[start] = 0;
		
		PriorityQueue<Node> pq = new PriorityQueue<>(); //오름차순
		pq.add(new Node(start, 0));
		
		while(!pq.isEmpty()) {
			Node curNode = pq.poll();
			int now = curNode.v;
			int cost = curNode.cost;
			
			if(dist[now]<cost) continue;
			for(int i=0;i<graph[now].size();i++) {
				int next = graph[now].get(i).v;
				int nextCost = cost + graph[now].get(i).cost;
				if(nextCost < dist[next]) {
					dist[next] = nextCost;
					pq.add(new Node(next, nextCost));
				}
			}
		}
		
	}
	
    public static void main(String[] args) throws IOException {
    	
    	int V,E;
    	int start;
    	int u,v,w;
    	
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	V = Integer.parseInt(st.nextToken());
    	E = Integer.parseInt(st.nextToken());
    	start = Integer.parseInt(br.readLine());
    	
    	graph = new ArrayList[V+1];
    	dist = new int[V+1];
    	
    	for(int i=1;i<=V;i++) {
    		graph[i] = new ArrayList<>();
    		dist[i] = Integer.MAX_VALUE;
    	}
    	
    	for(int i=0;i<E;i++) {
    		st = new StringTokenizer(br.readLine());
    		u = Integer.parseInt(st.nextToken());
    		v = Integer.parseInt(st.nextToken());
    		w = Integer.parseInt(st.nextToken());
    		
    		graph[u].add(new Node(v,w));
    	}
    	
    	dijkstra(start);
    	
    	StringBuilder sb = new StringBuilder();
    	for(int i=1;i<=V;i++) {
    		if(dist[i]==Integer.MAX_VALUE) sb.append("INF\n");
    		else sb.append(dist[i]+"\n");
    	}
    	
    	System.out.println(sb);
    }
}