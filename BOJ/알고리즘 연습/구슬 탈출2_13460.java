import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static char EXIT = 'O';

    static char[][] map;
    static boolean[][][][] visited;
    static Ball redBall;
    static Ball blueBall;

    static int[] dy = {0, 0, 1, -1};
    static int[] dx = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        visited = new boolean[n][m][n][m];

        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = str.charAt(j);

                if (map[i][j] == 'R') {
                    redBall = new Ball(i, j, 0);
                }
                if (map[i][j] == 'B') {
                    blueBall = new Ball(i, j, 0);
                }
            }
        }

        System.out.println(bfs(redBall, blueBall));
    }

    static int bfs(Ball redBall, Ball blueBall) {
        Queue<Ball> redQ = new LinkedList<>();
        Queue<Ball> blueQ = new LinkedList<>();

        redQ.offer(redBall);
        blueQ.offer(blueBall);

        visited[redBall.y][redBall.x][blueBall.y][blueBall.x] = true;

        while(!redQ.isEmpty() && !blueQ.isEmpty()) {
            Ball curRedBall = redQ.poll();
            Ball curBlueBall = blueQ.poll();

            if(curRedBall.moveCount > 10) {
                return -1;
            }

            if(map[curBlueBall.y][curBlueBall.x] == EXIT) {
                continue;
            }

            if(map[curRedBall.y][curRedBall.x] == EXIT) {
                return curRedBall.moveCount;
            }

            for(int i=0;i<4;i++){
                int[] nextRedBall = move(i, curRedBall.y, curRedBall.x);
                int[] nextBlueBall = move(i, curBlueBall.y, curBlueBall.x);

                if(nextRedBall[0] == nextBlueBall[0] && nextRedBall[1] == nextBlueBall[1]
                        && map[nextRedBall[0]][nextRedBall[1]] != EXIT) {
                    int redBallDist = Math.abs(nextRedBall[0] - curRedBall.y) + Math.abs(nextRedBall[1] - curRedBall.x);
                    int blueBallDist = Math.abs(nextBlueBall[0] - curBlueBall.y) + Math.abs(nextBlueBall[1] - curBlueBall.x);

                    if(redBallDist > blueBallDist) {
                        nextRedBall[0] -= dy[i];
                        nextRedBall[1] -= dx[i];
                    }
                    if(blueBallDist > redBallDist) {
                        nextBlueBall[0] -= dy[i];
                        nextBlueBall[1] -= dx[i];
                    }
                }

                if(!visited[nextRedBall[0]][nextRedBall[1]][nextBlueBall[0]][nextBlueBall[1]]) {
                    visited[nextRedBall[0]][nextRedBall[1]][nextBlueBall[0]][nextBlueBall[1]] = true;

                    redQ.offer(new Ball(nextRedBall[0], nextRedBall[1], curRedBall.moveCount + 1 ));
                    blueQ.offer(new Ball(nextBlueBall[0], nextBlueBall[1], curBlueBall.moveCount + 1));
                }
            }
        }
        return -1;
    }

    private static int[] move(int i, int ballY, int ballX) {
        while(true) {
            ballY += dy[i];
            ballX += dx[i];

            if(map[ballY][ballX] == EXIT) {
                return new int[]{ballY, ballX};
            }

            if(map[ballY][ballX] == '#') {
                ballY -= dy[i];
                ballX -= dx[i];
                return new int[]{ballY, ballX};
            }
        }
    }

    static class Ball {
        int y;
        int x;
        int moveCount;

        public Ball(int y, int x, int moveCount) {
            this.y = y;
            this.x = x;
            this.moveCount = moveCount;
        }
    }
}
