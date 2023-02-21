import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int[][] map;
    static int[][] dp;
    static final int INF = 16_000_000;    // MAX : 11,000,000

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];

        /*
         * 1차원: 현재 위치한 도시
         * 2차원: 지금까지 방문한 도시 2진수로 표현 (비트마스킹 이용)
         * */
        dp = new int[n][(1 << n) - 1];

        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int dist = Integer.parseInt(st.nextToken());
                map[i][j] = dist;
            }
        }

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        System.out.println(dfs(0, 1));
    }

    private static int dfs(int curCity, int visited) {

        /*
         * 모든 도시 방문한 경우
         * 블록 안 조건문: 만약 0번째 도시로의 경로가 없으면 탐색 패스
         * */
        if (visited == (1 << n) - 1) {
            if (map[curCity][0] == 0) {
                return INF;
            }
            return map[curCity][0];
        }

        /*
         * 이미 방문한 도시인 경우
         * */
        if (dp[curCity][visited] != -1) {
            return dp[curCity][visited];
        }

        dp[curCity][visited] = INF;

        /* *
         * 방문하지 않은 도시 탐색
         * 방문하지 않고 경로가 있는 경우
         */
        for (int i = 0; i < n; i++) {

            int nextVisited = visited | (1 << i);

            if ((visited & (1 << i)) == 0 && map[curCity][i] != 0) {
                dp[curCity][visited] = Math.min(dp[curCity][visited], dfs(i, nextVisited) + map[curCity][i]);
            }
        }

        return dp[curCity][visited];
    }
}