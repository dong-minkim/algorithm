import java.util.Scanner;

public class Main {

    public static final int MOD = 1_000_000_007;
    public static final long[][] originMatrix = {{1, 1}, {1, 0}};

    /*
     *                n
     *       | 1   1 |    | F(n+1)  F(n)  |
     * A^n = |       |  = |               |
     *       | 1   0 |    |  F(n)  F(n-1) |
     * */

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        long N = scan.nextLong();

        long[][] answer = pow(originMatrix, N-1);

        System.out.println(answer[0][0]);
    }

    public static long[][] pow(long[][] matrix, long exp) {
        if (exp == 1L || exp==0) {
            return matrix;
        }

        long[][] result = pow(matrix, exp / 2);

        result = multiply(result, result);

        if (exp % 2 == 1L) {
            result = multiply(result, originMatrix);
        }

        return result;
    }


    public static long[][] multiply(long[][] m1, long[][] m2) {

        long[][] result = new long[2][2];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    result[i][j] += m1[i][k] * m2[k][j];
                    result[i][j] %= MOD;
                }
            }
        }
        return result;
    }
}