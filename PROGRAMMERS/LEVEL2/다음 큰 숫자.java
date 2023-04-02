class Solution {
    public int solution(int n) {
        int inputBinaryCnt = Integer.bitCount(n);
        while(true) {
            if(Integer.bitCount(++n) == inputBinaryCnt) {
                return n;
            }
        }
    }
}