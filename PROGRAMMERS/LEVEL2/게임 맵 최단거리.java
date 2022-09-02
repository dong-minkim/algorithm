import java.util.*;
import java.util.Map.Entry;

class Solution {
	
	static int[] dx = {1,-1,0,0};
	static int[] dy = {0,0,1,-1};
	static int min = Integer.MIN_VALUE;
	
    public int solution(int[][] maps) {
    	
    	int[][] visited = new int[maps.length][maps[0].length];
    	Queue<int[]> q = new LinkedList<int[]>();
    	q.add(new int[]{0,0});
    	
    	while(!q.isEmpty()) {
    		int[] cur = q.poll();
    		int y = cur[0];
    		int x = cur[1];
    		visited[0][0] = 1;
    		
    		for(int i=0;i<4;i++) {
    			int Y = y + dy[i];
    			int X = x + dx[i];
    			
    			if(Y<0 || Y>maps.length-1 || X<0 || X>maps[0].length-1) continue;
    			if(visited[Y][X]==0 && maps[Y][X]==1) {
    				visited[Y][X] = visited[y][x] + 1;
    				q.add(new int[] {Y,X});
    			}
    		}
    	}
        int answer = visited[maps.length-1][maps[0].length-1];
        
        return answer==0 ? -1 : answer;
    }
}
