import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int ans = Integer.MAX_VALUE;

        int[] memories = new int[n + 1];
        int[] costs = new int[n + 1];
        int[][] dp = new int[n + 1][100001];

        StringTokenizer st1 = new StringTokenizer(br.readLine());
        StringTokenizer st2 = new StringTokenizer(br.readLine());

        for (int i = 1; i <= n; i++) {
            memories[i] = Integer.parseInt(st1.nextToken());
            costs[i] = Integer.parseInt(st2.nextToken());
        }

        for (int i = 1; i <= n; i++) {
            int memory = memories[i];
            int cost = costs[i];

            for (int j = 1; j <= 10000; j++) {
                if (j < cost) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - cost] + memory);
                }
            }
        }
        for (int cost = 1; cost <= 10000; cost++) {
            if (dp[n][cost] >= m) {
                System.out.println(cost);
                return;
            }
        }
    }
}