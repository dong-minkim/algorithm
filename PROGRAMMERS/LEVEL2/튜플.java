import java.util.*;
import java.util.Map.Entry;

class Solution {
    public ArrayList<Integer> solution(String s) {
        ArrayList<Integer> answer =new ArrayList<Integer>();
        HashMap<Integer, Integer> frequency = new HashMap<Integer, Integer>();
        
        s = s.replace("{", "");
        s = s.replace("}", "");
        String[] str = s.split(",");
        
        for(int i=0;i<str.length;i++) {
        	int tmp = Integer.parseInt(str[i]);
        	if(frequency.containsKey(tmp)) {
        		frequency.put(tmp, frequency.get(tmp) + 1);
        	}
        	else frequency.put(tmp,1);
        }
        
        List<Entry<Integer, Integer>> mapEntry = new ArrayList<Map.Entry<Integer,Integer>>(frequency.entrySet());
        for(int i=0;i<mapEntry.size();i++) {
        }
        
        
        mapEntry.sort(Entry.comparingByValue());
        
        for(Entry entry : mapEntry) {
        	answer.add((int) entry.getKey());
        }
        
        Collections.reverse(answer);
        
        
        return answer;
    }
}