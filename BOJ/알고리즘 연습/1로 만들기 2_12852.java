import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] dp = new int[N + 1];
        int[] path = new int[N + 1];

        dp[1] = 0;
        for (int i = 2; i <= N; i++) {

            dp[i] = dp[i - 1] + 1;
            path[i] = i - 1;

            if (i % 3 == 0) {
                if (dp[i / 3] + 1 < dp[i]) {
                    dp[i] = dp[i / 3] + 1;
                    path[i] = i / 3;
                }
            }

            if (i % 2 == 0) {
                if (dp[i / 2] + 1 < dp[i]) {
                    dp[i] = dp[i / 2] + 1;
                    path[i] = i / 2;
                }
            }
        }

        System.out.println(dp[N]);
        while (N > 0) {
            System.out.print(N + " ");
            N = path[N];
        }
    }
}