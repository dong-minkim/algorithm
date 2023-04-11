import java.util.StringTokenizer;

class Solution {
    public int solution(int n, int k) {
        int answer = 0;

        String number = Integer.toString(n, k);
        StringTokenizer st = new StringTokenizer(number, "0");

        for (int i = 0; st.hasMoreTokens(); i++) {
            if (isPrime(Long.parseLong(st.nextToken()))) {
                answer++;
            }
        }
        return answer;
    }

    boolean isPrime(double number) {
        if (number < 2) return false;
        for (long i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
}