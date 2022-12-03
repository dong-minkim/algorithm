import java.io.*;
import java.util.*;

public class Main {

    static int dy[] = {-1, 1, 0, 0};
    static int dx[] = {0, 0, 1, -1};

    static Shark map[][];
    static int R;
    static int C;
    static int answer = 0;
    static List<Shark> sharks = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        int sharkAmount = Integer.parseInt(st.nextToken());

        map = new Shark[R + 1][C + 1];

        for (int i = 0; i < sharkAmount; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken()) - 1;
            int z = Integer.parseInt(st.nextToken());
            map[r][c] = new Shark(r, c, s, d, z);
            sharks.add(new Shark(r, c, s, d, z));
        }

        for (int i = 1; i <= C; i++) {
            fishing(i);
            moveShark();
        }
        System.out.println(answer);
    }

    static void moveShark() {
        for (int i = 0; i < sharks.size(); i++) {
            Shark shark = sharks.get(i);
            int sharkSpeed = shark.s;

            if (shark.d < 2) {
                sharkSpeed %= (R - 1) * 2;
                while (sharkSpeed > 0) {
                    if (shark.r == 1) {
                        shark.d = 1;
                    }
                    if (shark.r == R) {
                        shark.d = 0;
                    }
                    shark.r += dy[shark.d];
                    sharkSpeed--;
                }
            } else {
                sharkSpeed %= (C - 1) * 2;
                while (sharkSpeed > 0) {
                    if (shark.c == 1) {
                        shark.d = 2;
                    }
                    if (shark.c == C) {
                        shark.d = 3;
                    }
                    shark.c += dx[shark.d];
                    sharkSpeed--;
                }
            }
        }
        map = new Shark[R + 1][C + 1];
        for (int i = sharks.size() - 1; i >= 0; i--) {
            Shark shark = sharks.get(i);
            if (map[shark.r][shark.c] == null) {
                map[shark.r][shark.c] = shark;
            } else {
                if (map[shark.r][shark.c].z > shark.z) {
                    sharks.remove(shark);
                } else {
                    sharks.remove(map[shark.r][shark.c]);
                    map[shark.r][shark.c] = shark;
                }
            }
        }
    }

    static void fishing(int c) {
        for (int i = 1; i <= R; i++) {
            if (map[i][c] != null) {
                answer += map[i][c].z;
                sharks.remove(map[i][c]);
                map[i][c] = null;
                break;
            }
        }
    }

    static class Shark {
        int r, c, s, d, z;

        public Shark(int r, int c, int s, int d, int z) {
            this.r = r;
            this.c = c;
            this.s = s;
            this.d = d;
            this.z = z;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Shark shark = (Shark) o;
            return z == shark.z;
        }
    }
}