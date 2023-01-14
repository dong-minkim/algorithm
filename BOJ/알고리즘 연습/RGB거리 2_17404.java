import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int INF = 1_000_000;
    static int answer = 1_000_000;

    public static void main(String[] args) throws IOException {

        int[][] house;
        int[][] dp;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        house = new int[N + 1][3];
        dp = new int[N + 1][3];

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                house[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < 3; i++) {
            /*
             * 첫 집 색깔
             * */
            for (int j = 0; j < 3; j++) {
                if (i == j) {
                    dp[1][i] = house[1][i];
                } else {
                    dp[1][j] = INF;
                }
            }

            for (int j = 2; j <= N; j++) {
                dp[j][0] = Math.min(dp[j - 1][1], dp[j - 1][2]) + house[j][0];
                dp[j][1] = Math.min(dp[j - 1][0], dp[j - 1][2]) + house[j][1];
                dp[j][2] = Math.min(dp[j - 1][0], dp[j - 1][1]) + house[j][2];
            }

            /*
             * 첫 집과 마지막 집은 색깔이 달라야하기 때문
             * */
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    answer = Math.min(answer, dp[N][j]);
                }
            }
        }
        System.out.println(answer);
    }
}