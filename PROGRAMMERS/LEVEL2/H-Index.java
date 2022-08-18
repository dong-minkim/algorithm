import java.util.*;
import java.util.Map.Entry;

class Solution {
    public int solution(int[] citations) {
    	int answer=0;
    	Arrays.sort(citations);
    	
    	for(int i=0;i<citations.length;i++) {
    		int h = citations.length-i;
    		
    		if(citations[i]>=h) {
    			answer=h;
    			break;
    		}
    	}
    	
    	return answer;
    }
}