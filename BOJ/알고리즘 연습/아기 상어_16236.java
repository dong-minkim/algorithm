import java.io.*;
import java.util.*;

public class Main {

    public static final int MAX_DISTANCE = 401, MAX_LENGTH = 21;
    public static int n, sharkY, sharkX, answer, eatCount = 0;
    public static int destinationDist, destinationY, destinationX = 0;
    public static int sharkSize = 2;
    public static int[][] map, visited;
    public static int[] dx = {0, 0, 1, -1}, dy = {-1, 1, 0, 0};

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        map = new int[n + 1][n + 1];
        visited = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 9) {
                    sharkY = i;
                    sharkX = j;
                    map[i][j] = 0;
                }
            }
        }

        while (true) {

            bfs(sharkY, sharkX);

            if (destinationY != MAX_LENGTH && destinationX != MAX_LENGTH) {
                answer += visited[destinationY][destinationX];

                eatCount++;

                if (eatCount == sharkSize) {
                    sharkSize++;
                    eatCount = 0;
                }

                map[destinationY][destinationX] = 0;

                sharkY = destinationY;
                sharkX = destinationX;
            } else {
                break;
            }
        }

        System.out.println(answer);
    }

    public static void bfs(int y, int x) {
        destinationDist = MAX_DISTANCE;
        destinationY = MAX_LENGTH;
        destinationX = MAX_LENGTH;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                visited[i][j] = -1;
            }
        }

        Queue<int[]> q = new LinkedList<>();
        visited[y][x] = 0;
        q.add(new int[]{y, x});

        while (!q.isEmpty()) {
            int[] current = q.poll();
            y = current[0];
            x = current[1];

            for (int i = 0; i < 4; i++) {
                int nextY = y + dy[i];
                int nextX = x + dx[i];

                if (nextY < 1 || nextY > n || nextX < 1 || nextX > n) continue;
                if (visited[nextY][nextX] != -1 || map[nextY][nextX] > sharkSize) continue;

                visited[nextY][nextX] = visited[y][x] + 1;

                if (map[nextY][nextX] != 0 && map[nextY][nextX] < sharkSize) {

                    if (destinationDist > visited[nextY][nextX]) {
                        destinationY = nextY;
                        destinationX = nextX;
                        destinationDist = visited[nextY][nextX];
                    } else if (destinationDist == visited[nextY][nextX]) {
                        if (destinationY == nextY) {
                            if (destinationX > nextX) {
                                destinationY = nextY;
                                destinationX = nextX;
                            }
                        } else if (destinationY > nextY) {
                            destinationY = nextY;
                            destinationX = nextX;
                        }
                    }
                }

                q.add(new int[]{nextY, nextX});
            }
        }

    }
}