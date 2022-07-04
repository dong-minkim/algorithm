import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    public List solution(int n, int[] arr1, int[] arr2) {
        List<String> answer = new ArrayList<String>();
        
        for(int i=0;i<n;i++) {
        	int num = arr1[i] | arr2[i];
        	String str="";
        	
        	for(int j=0;j<n;j++) {
        		if(num%2==0) str=" "+str;
        		else str="#"+str;
        		
        		num/=2;
        	}
        	answer.add(str);
        }
        
        return answer;
    }
}