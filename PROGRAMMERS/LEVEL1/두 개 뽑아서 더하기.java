import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    public List solution(int[] numbers) {
        
    	Set<Integer> set = new HashSet<Integer>();
        
        for(int i=0;i<numbers.length;i++) {
        	for(int j=i+1;j<numbers.length;j++) {
        		set.add(numbers[i]+numbers[j]);
        	}
        }
        
        List answer = new ArrayList(set);
        Collections.sort(answer);
        
        return answer;
    }
}