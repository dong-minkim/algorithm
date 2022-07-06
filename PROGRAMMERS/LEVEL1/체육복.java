import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int[] student = new int[30];
        
        Arrays.fill(student, 1);
        for(int i=0;i<lost.length;i++) student[lost[i]-1]--;
        for(int i=0;i<reserve.length;i++) student[reserve[i]-1]++;
        
        for(int i=0;i<n;i++) {
        	if(student[i]==2 && i>0 &&student[i-1]==0) {
        		student[i]--;
        		student[i-1]++;
        	}
        	if(student[i]==2 && i<n-1 && student[i+1]==0) {
        		student[i]--;
        		student[i+1]++;
        	}
        }
        for(int i=0;i<n;i++) 
        	if(student[i]>0)
        		answer++;
        
        return answer;
    }
}