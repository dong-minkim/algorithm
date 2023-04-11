class Solution {

    int[] dy = {1, 0, -1, 0};
    int[] dx = {0, 1, 0, -1};

    int[][] map = new int[11][11];
    boolean[][][][] street = new boolean[11][11][11][11];

    public int solution(String dirs) {
        int answer = 0;

        int curY = 5;
        int curX = 5;
        int dir = 0;

        int nextY = curY;
        int nextX = curX;
        for (int i = 0; i < dirs.length(); i++) {
            if (dirs.charAt(i) == 'U') {
                dir = 0;
            }
            if (dirs.charAt(i) == 'R') {
                dir = 1;
            }
            if (dirs.charAt(i) == 'D') {
                dir = 2;
            }
            if (dirs.charAt(i) == 'L') {
                dir = 3;
            }

            nextY += dy[dir];
            nextX += dx[dir];

            if (nextY < 0 || nextX < 0 || nextY >= 11 || nextX >= 11) {
                nextY -= dy[dir];
                nextX -= dx[dir];
                continue;
            }

            if(!street[curY][curX][nextY][nextX]) {
                street[curY][curX][nextY][nextX] = true;
                street[nextY][nextX][curY][curX] = true;
                answer++;
            }

            curY = nextY;
            curX = nextX;
        }

        return answer;
    }
}