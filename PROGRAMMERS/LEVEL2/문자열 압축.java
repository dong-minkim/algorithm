class Solution {
    public int solution(String s) {
        int answer = s.length();
        
        for(int i=1;i<=s.length()/2;i++) {
        	StringBuilder sb = new StringBuilder();
        	String cur = s.substring(0,i);
        	String next = "";
        	int cnt=1;
        	
        	for(int j=i;j<=s.length();j+=i) {
        		if(s.length()<=j+i) next = s.substring(j);
        		else next=s.substring(j,j+i);
        		
        		
        		if(cur.equals(next)) {
        			cnt++;
        		}
        		else if(cnt==1) {
        			sb.append(cur);
        			cur = next;
       			}
       			else {
       				sb.append(cnt).append(cur);
       				cur = next;
       				cnt=1;
       			}
       		}
        	 if(i!=cur.length()) sb.append(cur);
             	
             answer = Math.min(answer, sb.length());
       	}
       
        return answer;
    }
}