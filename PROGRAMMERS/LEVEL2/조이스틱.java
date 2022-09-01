import java.util.*;
import java.util.Map.Entry;

class Solution {
    public int solution(String name) {
        int answer = 0;
        int length = name.length();
        int move = length - 1;
        
        //각 글자 변경
        for(int i=0;i<name.length();i++) {
        	
        	answer += Math.min(name.charAt(i)-'A', 'Z'+ 1 - name.charAt(i));
        	
        	int idx = i+1;
        	while(idx<length && name.charAt(idx)=='A') idx++;
        	
        	move = Math.min(move, i*2 + length - idx);
        	move = Math.min(move, (length-idx)*2 + i);
        	
        }
        answer+=move;
        
        return answer;
    }
}