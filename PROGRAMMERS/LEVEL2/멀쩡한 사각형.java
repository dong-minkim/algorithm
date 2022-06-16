class Solution {
    public long solution(int w, int h) {
        long answer = 1;
        
        answer = ((long)w * (long)h) - (long)w - (long)h;
        
        while (h != 0) {
            int tmp = w % h;
            w = h;
            h = tmp;
        }
        answer += w;

        return answer;
    }
}