import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        double total = stages.length;
        List<double[]> fail = new ArrayList<>();
        
        int cur=0;
        
        for(int i=1;i<=N;i++) {
        	for(int j=0;j<stages.length;j++) {
        		if(i==stages[j]) {
        			cur++;
        		}
        	}
        	if(cur==0) {
        		fail.add(new double[]{i,0});
        	}
        	else {
        		fail.add(new double[] {i,cur/total});
        		total-=cur;
        		cur=0;
        	}
        }
        
        fail.sort((o1,o2)->Double.compare(o2[1], o1[1]));
        
        for(int i=0;i<fail.size();i++) {
        	answer[i]=(int)fail.get(i)[0];
        }
        
        return answer;
    }
}