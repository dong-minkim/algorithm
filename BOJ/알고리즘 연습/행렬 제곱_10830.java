import java.util.Scanner;

public class Main {

    final static int MOD = 1000;
    public static int N;
    public static int[][] originMatrix;

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        N = scan.nextInt();
        long B = scan.nextLong();

        originMatrix = new int[N][N];


        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                originMatrix[i][j] = scan.nextInt() % MOD;
            }
        }

        int[][] answer = pow(originMatrix, B);

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                sb.append(answer[i][j]).append(' ');
            }
            sb.append('\n');
        }
        System.out.println(sb);
    }

    public static int[][] pow(int[][] matrix, long exp) {
        if(exp == 1L) {
            return matrix;
        }

        int[][] result = pow(matrix, exp / 2);

        result = multiply(result, result);

        if(exp % 2 == 1L) {
            result = multiply(result, originMatrix);
        }

        return result;
    }


    public static int[][] multiply(int[][] m1, int[][] m2) {

        int[][] result = new int[N][N];

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    result[i][j] += m1[i][k] * m2[k][j];
                    result[i][j] %= MOD;
                }
            }
        }
        return result;
    }
}