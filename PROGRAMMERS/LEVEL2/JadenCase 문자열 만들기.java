import java.util.*;

class Solution {
    public String solution(String s) {
    	String answer ="";
    	
    	s = s.toLowerCase();
    	answer += String.valueOf(Character.toUpperCase(s.charAt(0)));
    	System.out.println(s);
		for (int i = 1; i < s.length(); i++) {
			if (answer.charAt(i) == ' ')
				answer += " ";
//			else if (answer.charAt(i - 1) == ' ')
//				answer += String.valueOf(Character.toUpperCase(s.charAt(i)));
//			else
//				answer += String.valueOf(s.charAt(i));
		}
    	
    	return answer;
    }
}