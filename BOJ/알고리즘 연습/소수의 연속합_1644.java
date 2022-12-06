import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    static boolean prime[];
    static final boolean YES = false;
    static final boolean NO = true;
    static ArrayList<Integer> primeNumbers = new ArrayList<>();

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        prime = new boolean[N + 1];
        prime[0] = prime[1] = NO;
        for (int i = 2; i * i <= N; i++) {
            if (prime[i] == YES) {
                for (int j = i * i; j <= N; j += i) {
                    prime[j] = NO;
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (prime[i] == YES) {
                primeNumbers.add(i);
            }
        }

        /*
         * 투 포인터
         * */
        int start = 0, end = 0, sum = 0, count = 0;
        while (true) {
            if (sum >= N) {
                sum -= primeNumbers.get(start++);
            } else if (end == primeNumbers.size()) {
                break;
            } else {
                sum += primeNumbers.get(end++);
            }

            if
            (N == sum) {
                count++;
            }

        }
        System.out.println(count);
    }
}