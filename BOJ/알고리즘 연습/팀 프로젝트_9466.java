import java.util.*;
import java.io.*;

public class Main {
    static int[] arr;
    static boolean[] visited;
    static boolean[] builtTeam;
    static int count;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int n = Integer.parseInt(br.readLine());
            arr = new int[n + 1];
            visited = new boolean[n + 1];
            builtTeam = new boolean[n + 1];
            count = 0;

            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 1; i <= n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            for (int i = 1; i <= n; i++) {
                dfs(i);
            }
            System.out.println(n - count);
        }
    }

    public static void dfs(int n) {
        if (visited[n]) {
            return;
        }

        visited[n] = true;
        int next = arr[n];

        if (!visited[next]) {
            dfs(next);
        } else {
            if (!builtTeam[next]) {
                count++;
                for(int i=next; i != n; i = arr[i]) {
                    count++;
                }
            }
        }
        builtTeam[n] = true;
    }
}