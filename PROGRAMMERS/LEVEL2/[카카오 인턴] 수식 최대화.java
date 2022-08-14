import java.util.*;

class Solution {
	
	static char[] op = {'+', '-', '*'};
	static long answer = 0;
	static ArrayList<Long> number = new ArrayList<Long>();
	static ArrayList<Character> oper = new ArrayList<Character>();
	static boolean[] visited = new boolean[3];
	
    public long solution(String expression) {
        
    	String num = "";
    	for(int i=0;i<expression.length();i++) {
    		if(!(expression.charAt(i)=='+' || expression.charAt(i)=='-' || expression.charAt(i)=='*'))
    			num += expression.charAt(i);
    		else { //연산자라면
    			number.add(Long.parseLong(num));
    			num = "";
    			oper.add(expression.charAt(i));
    		}
    	}
    	number.add(Long.parseLong(num));
    	
    	permutation(0, new char[3]);
    	
    	return answer;
    }
    
    public static void permutation(int dept, char[] permOp) {
    	if(dept == 3) {
    		ArrayList<Long> copyNumber = new ArrayList<Long>(number);
    		ArrayList<Character> copyOper = new ArrayList<Character>(oper);
    		
    		for(int i=0;i<3;i++) {
    			for(int j=0;j<copyOper.size();j++) {
    				if(permOp[i] == copyOper.get(j)) {
    					Long tmp = cal(copyNumber.remove(j), copyNumber.remove(j), permOp[i]);
    					copyNumber.add(j, tmp);
    					copyOper.remove(j);
    					j--;
    				}
    			}
    		}
    		answer = Math.max(Math.abs(copyNumber.get(0)), answer);
    	}
    	
    	for(int i=0;i<3;i++) {
    		if(visited[i]==false) {
    			visited[i]=true;
    			permOp[dept] = op[i];
    			permutation(dept+1, permOp);
    			visited[i]=false;
    		}
    	}
    }
    
    public static long cal(long num1, long num2, char operation) {
    	if(operation=='+') return num1+num2;
    	else if(operation=='-') return num1-num2;
    	else return num1*num2;
    }
}