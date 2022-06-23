import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

class Solution {
    public String[] solution(String[] record) {
        List<String> answer = new ArrayList<String>();
        HashMap<String, String> map = new HashMap<String, String>();
        
        
        for(int i=0;i<record.length;i++) {
        	StringTokenizer st = new StringTokenizer(record[i]);
        	String command = st.nextToken();
        	String userId = st.nextToken();
        	String userName = "";
        	
        	if(!command.equals("Leave")) userName=st.nextToken();
        	
        	if(command.equals("Enter")) {
        		map.put(userId, userName);
        		answer.add(userId+"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        	}
        	else if(command.equals("Leave")) {
        		answer.add(userId+"´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        	}
        	else if(command.equals("Change")) {
        		map.put(userId, userName);
        	}
        }
        
        for(int i=0;i<answer.size();i++) {
        	int index = answer.get(i).indexOf('´Ô');
        	String userId = answer.get(i).substring(0, index);
        	answer.set(i,answer.get(i).replace(userId,map.get(userId)));
        }
        
        return answer.toArray(new String[0]);
    }
}