import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    public boolean solution(String s) {
        
        for(int i=0;i<s.length();i++) {
        	if(!Character.isDigit(s.charAt(i))) return false;
        }
        
        return true;
    }
}