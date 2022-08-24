import java.util.*;
import java.util.Map.Entry;

class Solution {
	
	static ArrayList<Integer> array = new ArrayList<Integer>();
	static boolean[] visited = new boolean[7];
	
    public int solution(String numbers) {
        int answer = 0;
        
        for(int i=0;i<numbers.length();i++) {
        	dfs(numbers, i+1, "");
        }
        
        for(int i=0;i<array.size();i++) {
        	if(isPrime(array.get(i))) answer++;
        }
        
        return answer;
    }
    
    static void dfs(String inputNumber, int length, String number) {
    	if(number.length() == length) {
    		if(!array.contains(Integer.parseInt(number))) {
    			array.add(Integer.parseInt(number));
    		}
    	}
    	
    	for(int i=0;i<inputNumber.length();i++) {
    		if(!visited[i]) {
    			visited[i] = true;
    			number += inputNumber.charAt(i);
    			dfs(inputNumber, length, number);
    			visited[i] = false;
    			number = number.substring(0, number.length()-1);
    			
    		}
    	}
    	
    }
    
    static boolean isPrime(int num) {
    	if(num<2) return false;
    	
    	for(int i=2;i*i<=num;i++) {
    		if(num%i==0) return false;
    	}
    	
    	return true;
    }
}