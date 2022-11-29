import java.util.*;

public class Main {

    static int r, c;
    static int[][] board;
    static boolean[] alphaVisited;
    static int[] dy = {0, 0, 1, -1};
    static int[] dx = {1, -1, 0, 0};
    static int max = 0;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        r = scan.nextInt();
        c = scan.nextInt();
        scan.nextLine();

        board = new int[r][c];
        for (int i = 0; i < r; i++) {
            String str = scan.nextLine();
            for (int j = 0; j < c; j++) {
                board[i][j] = str.charAt(j) - 'A';
            }
        }

        alphaVisited = new boolean[26];
        dfs(0, 0, 1);
        System.out.println(max);
    }

    public static void dfs(int y, int x, int len) {
        max = Math.max(max, len);
        alphaVisited[board[y][x]] = true;

        for (int i = 0; i < 4; i++) {
            int Y = y + dx[i];
            int X = x + dy[i];
            if (Y >= 0 && X >= 0 && Y < r && X < c) {
                if (alphaVisited[board[Y][X]] == false) {
                    dfs(Y, X, len + 1);
                    alphaVisited[board[Y][X]] = false;
                }
            }
        }
    }
}
