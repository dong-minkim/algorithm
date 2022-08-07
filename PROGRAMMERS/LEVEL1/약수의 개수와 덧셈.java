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
	
    static public int solution(int left, int right) {
        int answer = 0;
        for(int i=left;i<=right;i++) {
        	if(Math.pow((int)Math.sqrt(i), 2)==i) {
        		answer-=i;
        	}
        	else answer+=i;
        }
        return answer;
    }
}