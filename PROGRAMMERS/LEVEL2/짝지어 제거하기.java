import java.util.Stack;

class Solution
{
    public int solution(String s)
    {
    	int answer;
    	
        Stack<Character> list = new Stack<>();
        
        
        
        for(int i=0;i<s.length();i++) {
        	if(list.isEmpty()) list.push(s.charAt(i));
        	else if(s.charAt(i)==list.peek()) list.pop();
        	else list.push(s.charAt(i));
        }
        
        if(list.isEmpty()) answer=1;
        else answer=0;
        
        return answer;
    }
}