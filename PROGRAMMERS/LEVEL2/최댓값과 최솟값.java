import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        ArrayList<Integer> number = new ArrayList<Integer>();
        String[] tmp = s.split(" ");
        
        for(String str : tmp) {
        	number.add(Integer.parseInt(str));
        }
        
        answer = Collections.min(number) + " " + Collections.max(number);
        
        return answer;
    }
}