import java.util.*;
import java.util.Map.Entry;

class Solution {
    
	static class Node implements Comparable<Node>{
		int v,cost;
		public Node(int v, int cost) {
			this.v = v;
			this.cost = cost;
		}
		
		@Override
		public int compareTo(Solution.Node o) {
			// TODO Auto-generated method stub
			return this.cost - o.cost;
		}
	}
	
	static int[] dist;
	static ArrayList<ArrayList<Node>> graph = new ArrayList<ArrayList<Node>>();
	
	public int solution(int N, int[][] road, int K) {
        int answer = 0;
        dist = new int[N+1];
        
        for(int i=0;i<=N;i++) {
        	graph.add(new ArrayList<>());
        	dist[i] = Integer.MAX_VALUE;
        }
        
        for(int i=0;i<road.length;i++) {
        	graph.get(road[i][0]).add(new Node(road[i][1], road[i][2]));
        	graph.get(road[i][1]).add(new Node(road[i][0], road[i][2]));
        }
        
        dijkstra(1);
        
        for(int d : dist) {
        	if(d<=K) answer++;
        }
        
        return answer;
    }
	
	static void dijkstra(int start) {
		dist[start] = 0;
		PriorityQueue<Node> pq = new PriorityQueue<Solution.Node>();
		pq.add(new Node(start, 0));
		
		while(!pq.isEmpty()) {
			Node curNode = pq.poll();
			int now = curNode.v;
			int nowCost = curNode.cost;
			
			if(dist[now] < nowCost) continue;
			for(int i=0;i<graph.get(now).size();i++) {
				int next = graph.get(now).get(i).v;
				int nextCost = graph.get(now).get(i).cost + nowCost;
				if(nextCost < dist[next]) {
					dist[next] = nextCost;
					pq.add(new Node(next,nextCost));
				}
			}
		}
	}
	
	
}

