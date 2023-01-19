import java.io.*;
import java.util.*;

public class Main {

    private static int[][] dp;
    private static List<List<Integer>> relations;
    private static boolean[] visited;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        relations = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            relations.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            relations.get(a).add(b);
            relations.get(b).add(a);
        }

        dp = new int[n + 1][2];
        visited = new boolean[n+1];
        solution(1);
        System.out.println(Math.min(dp[1][0], dp[1][1]));
    }

    static void solution(int current) {
        visited[current] = true;
        dp[current][0] = 0;
        dp[current][1] = 1;

        for (int child : relations.get(current)) {
            if(visited[child]) continue;
            solution(child);
            dp[current][0] += dp[child][1];
            dp[current][1] += Math.min(dp[child][0], dp[child][1]);
        }
    }
}