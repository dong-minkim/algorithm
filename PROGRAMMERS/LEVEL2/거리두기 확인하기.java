import java.util.*;

class Solution {
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        
        for(int k=0;k<5;k++) {
        	String[] place = places[k]; 
        	answer[k]=1;
        	
            for(int i=0;i<5; i++) {
            	for(int j=0;j<5; j++) {
            		if(place[i].charAt(j) == 'P') {
            			if(!bfs(i,j,place)) { 
            				answer[k]=0;
            			}
            		}
            	}
            }
        }
        
        return answer;
    }
    
    public static boolean bfs(int x, int y, String[] p) {
    	int[] dy = {1,-1,0,0};
    	int[] dx = {0,0,1,-1};
    	
    	Queue<int[]> q = new LinkedList<int[]>();
    	q.add(new int[] {x,y});
    	
    	while(!q.isEmpty()) {
    		int[] now = q.poll();
    		
    		for(int i=0;i<4;i++) {
    			int Y = now[1]+dy[i];
    			int X = now[0]+dx[i];
    			
    			if(Y==y && X==x) continue;
    			if(Y<0 || Y>=5 || X<0 || X>=5) continue;
    			
    			int dist = Math.abs(Y-y) + Math.abs(X-x);
    			
    			if(p[X].charAt(Y)=='P' && dist<=2) return false;
    			else if(p[X].charAt(Y)=='O' && dist<2) q.add(new int[] {X,Y});
    		}
    	}
    	return true;
    }
}