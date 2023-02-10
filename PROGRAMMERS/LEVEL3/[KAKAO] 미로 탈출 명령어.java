import java.util.stream.Collectors;
import java.util.stream.Stream;

class Solution {
    static int[] dx = {1, 0, 0, -1};
    static int[] dy = {0, -1, 1, -0};
    static String[] move = {"d", "l", "r", "u"};
    static String answer = "";
    static boolean isPath = false;

    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        int distance = getDistance(x, y, r, c);

        if (distance > k || (k - distance) % 2 == 1) {
            return "impossible";
        }
        getPath(n, m, x, y, r, c, "", k - 1);

        return answer;
    }

    static void getPath(int n, int m, int x, int y, int r, int c, String path, int moveCnt) {
        if (isPath) return;

        for (int i = 0; i < 4; i++) {
            if (isPath) return;
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (nextX < 1 || nextY < 1 || nextX > n || nextY > m) continue;
            if(getDistance(nextX, nextY, r, c) > moveCnt) continue;
            if (moveCnt > 0) {
                getPath(n, m, nextX, nextY, r, c, path + move[i], moveCnt - 1);
            }

            if (nextX == r && nextY == c && moveCnt == 0) {
                answer = path + move[i];
                isPath = true;
                return;
            }
        }
    }

    static int getDistance(int x, int y, int r, int c) {
        return Math.abs(r - x) + Math.abs(c - y);
    }
}