import java.util.*;
import java.util.Map.Entry;

class Solution {
    public int solution(String[][] clothes) {
    	int answer = 1;
    	
    	HashMap<String, Integer> map = new HashMap<String, Integer>();
    	
    	for(int i=0;i<clothes.length;i++) {
    		String type = clothes[i][1];
    		map.put(type, map.getOrDefault(type, 0) + 1);
    	}
    	
    	for(String key : map.keySet()) {
    		answer *= map.get(key) + 1;
    	}
    	
    	
        return answer - 1;
    }
}