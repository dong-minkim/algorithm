import java.util.*;

class Solution {
    public Queue<Integer> solution(int[] progresses, int[] speeds) {
        
        Queue<Integer> tmp = new LinkedList<Integer>();
        Queue<Integer> answer = new LinkedList<Integer>();
        
        for(int i=0;i<progresses.length;i++) {
        	tmp.add((99-progresses[i])/speeds[i] + 1);
        }
        
        int cnt=1;
        int temp = tmp.poll();
        while(!tmp.isEmpty()) {
        	if(temp>=tmp.peek()) { 
                tmp.poll(); 
                cnt++;
            }
        	else {
        		answer.add(cnt);
        		temp = tmp.poll();
        		cnt=1;
        	}
        }
        answer.add(cnt);
        
        return answer;
    }
}