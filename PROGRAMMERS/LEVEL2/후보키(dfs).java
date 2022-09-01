import java.util.*;
import java.util.Map.Entry;

class Solution {
	
	static int columnEa;
	static int rowEa;
	static boolean[] visited;
	static List<String> answer = new ArrayList<String>();
	
    public int solution(String[][] relation) {
        
        columnEa = relation[0].length;
        rowEa = relation.length; 
        
        for(int i=0;i<columnEa;i++) {
        	visited = new boolean[columnEa];
        	dfs(0,i+1,0,relation);
        }
        
        return answer.size();
    }
    
    public static void dfs(int start, int depth, int cnt, String[][] relation) {
    	if(cnt == depth) {
    		Set<String> set = new HashSet<String>();
    		for(int i=0;i<rowEa;i++) {
    			String tmp = "";
    			for(int j=0;j<visited.length;j++) {
    				if(visited[j]) {
    					tmp += relation[i][j];
    				}
    			}
    			set.add(tmp);
    		}
    		if(set.size() == rowEa) {
    			String temp = "";
    			for(int i=0;i<visited.length;i++) {
    				if(visited[i]) {
    					temp += String.valueOf(i);
    				}
    			}
    			for(int i=0;i<answer.size();i++) {
    				int count = 0;
    				for(int j=0;j<answer.get(i).length();j++) {
    					if(temp.contains(String.valueOf(answer.get(i).charAt(j)))) count++;
    				}
    				if(count==answer.get(i).length()) return;
    			}
    			answer.add(temp);
    		}
    	}
    	
    	for(int i=start;i<columnEa;i++) {
    		if(!visited[i]) {
    			visited[i]=true;
    			dfs(i,depth, cnt+1, relation);
    			visited[i]=false;
    		}
    	}
    }
}