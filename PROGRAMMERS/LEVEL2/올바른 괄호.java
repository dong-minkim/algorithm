import java.util.*;
import java.util.Map.Entry;

class Solution {
    boolean solution(String s) {
        Stack<Character> stack = new Stack<Character>();
        
        for(int i=0;i<s.length();i++) {
        	
        	if(stack.isEmpty()) {
        		if(s.charAt(i)==')') return false;
        		else stack.add(s.charAt(i));
        	}
        	else {
        		if(s.charAt(i)=='(') stack.add(s.charAt(i));
        		else stack.pop();
        	}

        }
        if(!stack.isEmpty()) return false;
        return true;
    }
}