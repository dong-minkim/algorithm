import java.util.*;
import java.util.Map.Entry;

class Solution {
    public int[] solution(int brown, int yellow) {
        
        double length = brown/2 + 2;
        double area = brown + yellow;
        
        double diff = Math.sqrt(Math.pow(length, 2)- (4*area));
        
        
        double width = (diff + length)/2;
        double height = length - width;
        
        int[] answer = {(int)width, (int)height};
        
        
        return answer;
    }
}