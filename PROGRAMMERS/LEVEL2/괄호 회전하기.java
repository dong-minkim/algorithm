import java.util.*;
import java.util.Map.Entry;

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        for(int i=0;i<s.length();i++) {
        	char tmp = s.charAt(0);
        	s = s.substring(1) + tmp;
        	if(isCorrect(s)) {
        		answer++;
        	}
        }
        
        return answer;
    }

    public boolean isCorrect(String s){

        Stack<Character> stack = new Stack<>();

        for(int i = 0; i < s.length(); i++){
            if(stack.isEmpty()){
                stack.push(s.charAt(i));
            }else{
                if(s.charAt(i) == ']'){
                    if(stack.peek() == '['){
                        stack.pop();
                    }else{
                        stack.push(s.charAt(i));
                    }
                }else if(s.charAt(i) == ')'){
                    if(stack.peek() == '('){
                        stack.pop();
                    }else{
                        stack.push(s.charAt(i));
                    }
                }else if(s.charAt(i) == '}'){
                    if(stack.peek() == '{'){
                        stack.pop();
                    }else{
                        stack.push(s.charAt(i));
                    }
                }else{
                    stack.push(s.charAt(i));
                }
            }
        }

        if(stack.isEmpty()) return true;
        else return false;

    }
}