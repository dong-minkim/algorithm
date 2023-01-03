import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] matrix;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        matrix = new int[n][2];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            matrix[i][0] = Integer.parseInt(st.nextToken());
            matrix[i][1] = Integer.parseInt(st.nextToken());
        }
        System.out.println(solution(matrix));
    }

    static int solution(int[][] matrix) {
        int[][] dp = new int[n][n];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                dp[j][j + i] = Integer.MAX_VALUE;
                for (int k = 0; k < i; k++) {
                    int value = dp[j][j + k] + dp[j + k + 1][j + i] + matrix[j][0] * matrix[j + k][1] * matrix[j + i][1];
                    dp[j][j + i] = Math.min(dp[j][j + i], value);
                }
            }
        }
        return dp[0][n - 1];
    }
}