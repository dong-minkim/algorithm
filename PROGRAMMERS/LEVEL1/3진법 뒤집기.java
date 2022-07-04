import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = 0;
        
        List<Integer> tmp = new ArrayList<Integer>();
        
        while(n>0) {
        	tmp.add(n%3);
        	n/=3;
        }
        
        int mul=1;
        for(int i=tmp.size()-1;i>=0;i--) {
        	answer+=mul*tmp.get(i);
        	mul*=3;
        }
        
        return answer;
    }
}