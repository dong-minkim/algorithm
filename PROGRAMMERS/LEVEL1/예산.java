import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    public int solution(int[] d, int budget) {
        int answer = 0;
        int sum=0;
        
        Arrays.sort(d);
        if(d[answer]>budget) return 0;
        while(true) {
        	sum+=d[answer];
        	if(answer==d.length-1 || (sum+d[answer+1])>budget) {
        		break;
        	}
        	answer++;
        }
        answer++;
        
        return answer;
    }
}