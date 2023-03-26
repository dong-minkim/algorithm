import java.util.LinkedList;
import java.util.Queue;

class Solution {

    int[] dy = {0, -1, 0, 1};
    int[] dx = {1, 0, -1, 0};

    char[][] map;
    int[][] visited;
    int y;
    int x;

    public int solution(String[] board) {
        y = board.length;
        x = board[0].length();
        int startY = 0, startX = 0;

        map = new char[y][x];
        visited = new int[y][x];
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                map[i][j] = board[i].charAt(j);
                if ('R' == map[i][j]) {
                    startY = i;
                    startX = j;
                }
            }
        }

        return bfs(startY, startX);
    }

    int bfs(int startY, int startX) {

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{startY, startX});
        visited[startY][startX] = 1;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nextY = cur[0];
                int nextX = cur[1];

                while (true) {
                    nextY += dy[i];
                    nextX += dx[i];
                    if (nextY < 0 || nextY >= y || nextX < 0 || nextX >= x || 'D' == map[nextY][nextX]) {
                        nextY -= dy[i];
                        nextX -= dx[i];
                        break;
                    }
                }

                if (visited[nextY][nextX] == 0) {
                    if ('G' == map[nextY][nextX]) {
                        return visited[cur[0]][cur[1]];
                    }

                    visited[nextY][nextX] = visited[cur[0]][cur[1]] + 1;
                    q.offer(new int[]{nextY, nextX});
                }
            }
        }
        return -1;
    }
}