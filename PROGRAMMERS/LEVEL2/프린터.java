import java.util.*;
import java.util.Map.Entry;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 1;
        
        Queue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        Queue<int[]> q = new LinkedList<int[]>();
        
        for(int i=0;i<priorities.length;i++) {
        	pq.add(priorities[i]);
        	q.add(new int[] {i,priorities[i]});
        }
        
        while(!q.isEmpty()) {
        	int[] now = q.poll();
        	if(now[1]==pq.peek()) {
        		if(now[0]==location) {
        			return answer;
        		}
        		else {
        			answer++;
        			pq.poll();
        		}
        	}
        	else {
        		q.add(now);
        	}
        }
        
        
        
        return answer;
    }
}