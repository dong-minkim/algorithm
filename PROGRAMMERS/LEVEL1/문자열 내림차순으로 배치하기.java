import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    public String solution(String s) {
        
    	char[] str = s.toCharArray();
    	Arrays.sort(str);
    	
    	StringBuilder sb = new StringBuilder(new String(str));
    	
    	
    	return sb.reverse().toString();
    }
}