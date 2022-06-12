import java.util.HashMap;

class Solution {
    static String[] condition;
    static HashMap<Character,Integer> map ;
    static boolean[] visited;
    static int[] position;
    static int answer;
    
    public int solution(int n, String[] data) {
    	condition = data;
        map = new HashMap<>();
        visited = new boolean[8];
        position = new int[8];
        answer = 0;
        map.put('A',0);
        map.put('C',1);
        map.put('F',2);
        map.put('J',3);
        map.put('M',4);
        map.put('N',5);
        map.put('R',6);
        map.put('T',7);
        
        dfs(0);
        
        return answer;
    }
    
    public static void dfs(int cnt){
        if(cnt == 8){
            if(check()) answer++;
        }
        else{
            for(int i=0;i<8;i++){
                if(!visited[i]){
                    visited[i] = true;
                    position[cnt] = i;
                    dfs(cnt + 1);
                    visited[i] = false;
                }
            }
        }
    }
    
    public static boolean check(){
        int a,b,res;
        char op;
        for(String s : condition){
            a = position[map.get(s.charAt(0))];
            b = position[map.get(s.charAt(2))];
            op = s.charAt(3);
            res = s.charAt(4)-'0' + 1;
            
            if(op == '='){
            	if(Math.abs(a-b)!=res) 
            	return false;
            	}
            else if(op == '>'){
            	if(Math.abs(a-b) <= res) 
            	return false;
            	}
            else {
            	if(Math.abs(a-b) >= res) 
            	return false;
            	}
        }
        return true;
    }
}