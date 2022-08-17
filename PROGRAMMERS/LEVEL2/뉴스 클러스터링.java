import java.util.*;
import java.util.Map.Entry;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        
        ArrayList<String> arr1 = new ArrayList<String>();

        double unionCnt = 0;
        
        for(int i=0;i<str1.length()-1;i++) {
        	if(isAlphabet(str1.charAt(i)) && isAlphabet(str1.charAt(i+1))){
        		String str = str1.substring(i, i+2);
        		str = str.toLowerCase();
        		arr1.add(str);
        		
        		System.out.println(str);
        		
        		unionCnt++;
        	}
        }
        
        System.out.println("============");
        
        double intersactionCnt = 0;
        ArrayList<String> arr2 = new ArrayList<String>(arr1);
        for(int i=0;i<str2.length()-1;i++) {
        	if(isAlphabet(str2.charAt(i)) && isAlphabet(str2.charAt(i+1))){
        		String str = str2.substring(i, i+2);
        		str = str.toLowerCase();
        		
        		System.out.println(str);
        		
        		if(arr1.contains(str)) {
        			intersactionCnt++; 
        			arr1.remove(str);
        			unionCnt--;
        		}
        		
        		unionCnt++;
        	}
        }
        
        if(unionCnt == 0 ) return 65536;
        
        answer =(int) ((intersactionCnt / unionCnt) * 65536);
        
        return answer;
    }
    
    public static boolean isAlphabet(char ch) {
    	if('a'<=ch && ch<='z') return true;
    	if('A'<=ch && ch<='Z') return true;
    	
    	return false;
    }
}