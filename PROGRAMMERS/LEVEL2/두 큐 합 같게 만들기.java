import java.util.*;
import java.util.Map.Entry;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        long sum = 0;
        long sum1 = 0;
        long sum2 = 0;
        
        Queue<Integer> q1 = new LinkedList<Integer>();
        Queue<Integer> q2 = new LinkedList<Integer>();
        
        for(int i=0;i<queue1.length;i++) {
        	sum1 += queue1[i];
        	sum2 += queue2[i];
        	q1.add(queue1[i]);
        	q2.add(queue2[i]);
        }
        
        sum = sum1 + sum2;
        
        if(sum%2==1) return -1;
        
        sum /= 2;
        int cnt = 0;
        while(true) {
        	
        	if(cnt >= queue1.length * 3) return -1;
        	
        	if(sum1==sum) return cnt;
        	else if(sum1>sum) {
        		long tmp = q1.peek();
        		sum1 -= tmp;
        		sum2 += tmp;
        		q2.add(q1.poll());
        	}
        	else {
        		long tmp = q2.peek();
        		sum2 -= tmp;
        		sum1 += tmp;
        		q1.add(q2.poll());
        	}
        	cnt++;
        }
    }
}
