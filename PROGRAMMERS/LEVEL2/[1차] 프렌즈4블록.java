import java.util.LinkedList;
import java.util.Queue;

class Solution {
    char[][] map;
    boolean[][] square;

    public int solution(int m, int n, String[] board) {
        int answer = 0;

        map = new char[m][n];
        square = new boolean[m][n];

        // init
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = board[i].charAt(j);
                square[i][j] = false;
            }
        }

        boolean done = false;
        while (!done) {
            done = true;
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (isSquare(i, j)) {
                        done = false;
                    }
                }
            }

            answer += erase(m, n);
            resetSquare(m, n);
        }

        return answer;
    }

    int erase(int m, int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int bottom = m - 1;
            Queue<Character> q = new LinkedList<>();
            for (int j = m - 1; j >= 0; j--) {
                if (square[j][i] == true) {
                    cnt++;
                } else {
                    q.add(map[j][i]);
                }
            }

            // 블록 채우기
            while (!q.isEmpty()) {
                map[bottom--][i] = q.poll();
            }

            for (int j = bottom; j >= 0; j--) {
                map[j][i] = '0';
            }
        }
        return cnt;
    }

    boolean isSquare(int y, int x) {
        char standard = map[y][x];
        // 빈칸인 경우
        if (map[y][x] == '0') {
            return false;
        }

        if (standard == map[y][x + 1] && standard == map[y + 1][x] && standard == map[y + 1][x + 1]) {
            square[y][x] = true;
            square[y][x + 1] = true;
            square[y + 1][x] = true;
            square[y + 1][x + 1] = true;
            return true;
        }

        return false;
    }

    void resetSquare(int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                square[i][j] = false;
            }
        }
    }
}