import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;

        int num_1 = 0;
        int num_2 = 0;
        for (int i = 0; i < s.length(); i++) {
        	if (s.charAt(i) == 'p' || s.charAt(i) == 'P') num_1++;
        	if (s.charAt(i) == 'y' || s.charAt(i) == 'Y') num_2++;
        }
        if (num_1 != num_2) answer = false;

        return answer;
    }
}