import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int y;
    static int x;
    static int answer = Integer.MIN_VALUE;
    static int[][] map;
    static int[][] tmpMap;
    static final int[] dy = {0, 0, 1, -1};
    static final int[] dx = {1, -1, 0, 0};

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        y = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        map = new int[y][x];

        for (int i = 0; i < y; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < x; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0);

        System.out.println(answer);
    }

    public static void dfs(int wallCount) {
        if (wallCount == 3) {
            bfs();
            safeZoneCount();
            return;
        }

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;
                    dfs(wallCount + 1);
                    map[i][j] = 0;
                }
            }
        }
    }

    public static void bfs() {
        Queue<Point> q = new LinkedList<>();
        tmpMap = new int[y][x];

        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                tmpMap[i][j] = map[i][j];
            }
        }

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (map[i][j] == 2) {
                    q.offer(new Point(i, j));
                }
            }
        }

        while (!q.isEmpty()) {
            Point point = q.poll();
            int curY = point.y;
            int curX = point.x;

            for (int i = 0; i < 4; i++) {
                int nextY = curY + dy[i];
                int nextX = curX + dx[i];

                if (nextY < 0 || nextY >= y || nextX < 0 || nextX >= x) continue;
                if (tmpMap[nextY][nextX] == 0) {
                    tmpMap[nextY][nextX] = 2;
                    q.add(new Point(nextY, nextX));
                }
            }
        }
    }

    public static void safeZoneCount() {
        int count = 0;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (tmpMap[i][j] == 0) {
                    count++;
                }
            }
        }
        answer = Math.max(answer, count);
    }

    static class Point {
        int y;
        int x;

        Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}