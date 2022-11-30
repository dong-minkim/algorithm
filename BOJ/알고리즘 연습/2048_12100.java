import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static int n;
    private static int[][] map;
    private static int[][] temp;
    private static int[] directOfMove;
    private static boolean[][] visited;

    /*
     *  상, 우, 하, 좌
     * */
    private static int[] dy = {-1, 0, 1, 0};
    private static int[] dx = {0, 1, 0, -1};

    private static int max = 0;

    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(reader.readLine());

        directOfMove = new int[5];

        map = new int[n + 1][n + 1];
        StringTokenizer st;
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(reader.readLine());
            for (int j = 1; j <= n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0);

        System.out.println(max);

    }

    private static void dfs(int index) {

        if (index == 5) {
            confirm();
        } else {
            for (int i = 0; i < 4; i++) {
                directOfMove[index] = i;
                dfs(index + 1);
            }
        }
    }

    private static void confirm() {

        temp = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            temp[i] = map[i].clone();
        }

        //총 5번 이동의 모든 경우의 수 검사
        for (int round = 0; round < directOfMove.length; round++) {
            visited = new boolean[n + 1][n + 1];

            if (directOfMove[round] == 0) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        move(i, j, directOfMove[round]);
                    }
                }
            } else if (directOfMove[round] == 1) {
                for (int i = n; i >= 1; i--) {
                    for (int j = 1; j <= n; j++) {
                        move(j, i, directOfMove[round]);
                    }
                }
            } else if (directOfMove[round] == 2) {
                for (int i = n; i >= 1; i--) {
                    for (int j = 1; j <= n; j++) {
                        move(i, j, directOfMove[round]);
                    }
                }
            } else {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        move(j, i, directOfMove[round]);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (temp[i][j] > max) {
                    max = temp[i][j];
                }
            }
        }
    }

    private static void move(int y, int x, int dir) {

        if (temp[y][x] == 0) {
            return;
        }

        while (true) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 1 || nx < 1 || ny > n || nx > n) {
                return;
            }
            if (visited[ny][nx]) {
                return;
            }
            if (temp[ny][nx] == temp[y][x]) {
                visited[ny][nx] = true;
                temp[ny][nx] *= 2;
                temp[y][x] = 0;
                return;
            } else if (temp[ny][nx] != 0) {
                return;
            }

            temp[ny][nx] = temp[y][x];
            temp[y][x] = 0;
            y = ny;
            x = nx;

        }
    }
}