import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] dy = {1, -1, 0, 0};
    static int[] dx = {0, 0, 1, -1};

    static char[][] map;
    static boolean[][] visited;
    static boolean[] keys;
    static List<Point>[] closedGate = new ArrayList[26];
    static int h, w, document;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCase = Integer.parseInt(br.readLine());

        while (testCase-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            h = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            init();

            for (int i = 1; i < h + 1; i++) {
                String inputMap = br.readLine();
                for (int j = 1; j < w + 1; j++) {
                    map[i][j] = inputMap.charAt(j - 1);
                }
            }

            String inputKey = br.readLine();
            if (!inputKey.equals("0")) {
                for (int i = 0; i < inputKey.length(); i++) {
                    keys[inputKey.charAt(i) - 'a'] = true;
                }
            }

            document = 0;
            bfs();
            System.out.println(document);
        }

    }

    private static void bfs() {
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(0, 0));
        visited[0][0] = true;

        while (!q.isEmpty()) {
            Point cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nextY = cur.y + dy[i];
                int nextX = cur.x + dx[i];

                if (nextY < 0 || nextX < 0 || nextY > h + 1 || nextX > w + 1) {
                    continue;
                }
                if (map[nextY][nextX] == '*' || visited[nextY][nextX]) {
                    continue;
                }

                int info = map[nextY][nextX];
                if ('A' <= info && info <= 'Z') { //문
                    if (keys[info - 'A']) {
                        map[nextY][nextX] = '.';
                        visited[nextY][nextX] = true;
                        q.add(new Point(nextY, nextX));
                    } else {
                        closedGate[info - 'A'].add(new Point(nextY, nextX));
                    }
                } else if ('a' <= info && info <= 'z') { //열쇠
                    keys[info - 'a'] = true;
                    visited[nextY][nextX] = true;
                    q.add(new Point(nextY, nextX));
                    for (Point gatePoint : closedGate[info - 'a']) {
                        map[gatePoint.y][gatePoint.x] = '.';
                        visited[gatePoint.y][gatePoint.x] = true;
                        q.add(new Point(gatePoint.y, gatePoint.x));
                    }
                } else if ('$' == info) { //문서
                    document++;
                    map[nextY][nextX] = '.';
                    visited[nextY][nextX] = true;
                    q.add(new Point(nextY, nextX));

                } else { //이동 가능
                    visited[nextY][nextX] = true;
                    q.add(new Point(nextY, nextX));
                }
            }
        }
    }

    static private void init() {
        keys = new boolean[26];
        map = new char[h + 2][w + 2];
        visited = new boolean[h + 2][w + 2];
        for (int i = 0; i < 26; i++) {
            closedGate[i] = new ArrayList<>();
        }

        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                map[i][j] = '.';
            }
        }
    }

    private static class Point {
        int y;
        int x;

        Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}