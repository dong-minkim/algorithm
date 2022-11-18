import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        int row = Integer.parseInt(st.nextToken());
        int col = Integer.parseInt(st.nextToken());
        int[][] map = new int[row][col];

        for (int i = 0; i < row; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < col; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int result = 0;
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        while (true) {
            Queue<int[]> q = new LinkedList<>();
            q.add(new int[]{0, 0});
            map[0][0] = -1;
            while (!q.isEmpty()) {
                int[] now = q.poll();
                int x = now[0];
                int y = now[1];

                for (int i = 0; i < 4; i++) {
                    int X = x + dx[i];
                    int Y = y + dy[i];
                    if (X < 0 || Y < 0 || X >= row || Y >= col) continue;
                    if (map[X][Y] == 0) {
                        map[X][Y] = -1;
                        q.add(new int[]{X, Y});
                    }
                }
            }
            Queue<Integer> meltedX = new LinkedList<>();
            Queue<Integer> meltedY = new LinkedList<>();
            for (int x = 0; x < row; x++) {
                for (int y = 0; y < col; y++) {
                    int cnt = 0;
                    if (map[x][y] == 1) {
                        for (int d = 0; d < 4; d++) {
                            int X = x + dx[d];
                            int Y = y + dy[d];
                            if (X < 0 || Y < 0 || X >= row || Y >= col) continue;
                            if (map[X][Y] == -1) {
                                cnt++;
                                if (cnt >= 2) break;
                            }
                        }
                        if (cnt >= 2) {
                            meltedX.add(x);
                            meltedY.add(y);

                        }
                    }
                }
            }
            if (meltedX.isEmpty()) {
                System.out.println(result);
                return;
            }

            result++;
            while (!meltedX.isEmpty()) {
                map[meltedX.poll()][meltedY.poll()] = 0;
            }
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (map[i][j] == -1) {
                        map[i][j] = 0;
                    }
                }
            }
        }
    }
}