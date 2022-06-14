import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        Queue<Integer> pq = new PriorityQueue<Integer>();
        for(int x : scoville) {
        	pq.add(x);
        }
        
        while(pq.peek()<K && pq.size()>1) {
        	int num1 = pq.poll();
        	int num2 = pq.poll();
        	
        	pq.add(num1+(num2*2));
        	answer++;
        }
        
        if(pq.peek()<K) return -1;
        
        return answer;
    }
}