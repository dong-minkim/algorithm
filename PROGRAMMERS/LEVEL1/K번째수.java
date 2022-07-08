import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.Vector;

class Solution {
    public List<Integer> solution(int[] array, int[][] commands) {
        List<Integer> answer = new ArrayList<Integer>();
        
        for(int i=0;i<commands.length;i++) {
        	List<Integer> tmp = new ArrayList<Integer>();
        	for(int j=commands[i][0]-1;j<=commands[i][1]-1;j++) {
        		tmp.add(array[j]);
        	}
        	Collections.sort(tmp);
        	answer.add(tmp.get(commands[i][2]-1));
        }
        return answer;
    }
}