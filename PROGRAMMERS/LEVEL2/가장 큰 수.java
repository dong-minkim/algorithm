import java.util.*;
import java.util.Map.Entry;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String[] strArray = new String[numbers.length];
        
        for(int i=0;i<numbers.length;i++) {
        	strArray[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(strArray, new Comparator<String>() {
        	@Override
        	public int compare(String o1, String o2) {
        		// TODO Auto-generated method stub
        		return (o2+o1).compareTo(o1+o2);
        	}
		});
        
        for(String str : strArray) {
        	answer+=str;
        }
        
        if(answer.charAt(0)=='0') return "0";
        
        
        return answer;
    }
}