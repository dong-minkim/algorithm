import java.util.*;

class Solution {
	
    public String solution(String p) {
        String answer = process(p);
        return answer;
    }
    
    
    public static boolean isCorrect(String str){
        Stack<Character> stack = new Stack<>();
        
        for(int i=0; i<str.length(); i++){
            if(str.charAt(i) == '(') stack.push('(');
            else{
                if(stack.isEmpty()) return false;
                else stack.pop();
            }
        }
        return true;
    }
    
    
    public static String process(String p){
        if(p.length() == 0){
            return "";
        }
        
        String u = "";
        String v = "";
        int cnt = 0;
        
        //문자열 u,v 분리
        for(int i=0; i<p.length(); i++){
            if(p.charAt(i) == '('){
                cnt++;
            }
            else cnt--;
            u += p.charAt(i);
            if(cnt == 0){
                v = p.substring(i+1);
                break;
            }
        }
        
        
        if(isCorrect(u)){
            return u += process(v);
        }
        else{
            String tmp = "(";
            tmp += process(v);
            tmp += ")";
            u = u.substring(1, u.length()-1);
            
            for(int i=0; i<u.length(); i++){
                if(u.charAt(i) =='('){
                    tmp += ')';
                }else{
                    tmp += '(';
                }
            }
            return tmp;
        }
    }
}