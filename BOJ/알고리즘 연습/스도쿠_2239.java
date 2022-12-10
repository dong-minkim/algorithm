import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    static int[][] map;
    static List<int[]> blank;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        map = new int[9][9];
        blank = new ArrayList<int[]>();
        for (int i = 0; i < 9; i++) {
            String str = br.readLine();
            for (int j = 0; j < 9; j++) {
                map[i][j] = str.charAt(j) - '0';
                if (map[i][j] == 0) {
                    blank.add(new int[]{i, j});
                }
            }
        }

        game(0);
    }

    static void game(int idx) {

        if (idx == blank.size()) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    System.out.print(map[i][j]);
                }
                System.out.println();
            }
            System.exit(0);
        }

        int y = blank.get(idx)[0];
        int x = blank.get(idx)[1];

        boolean[] exist = new boolean[10];

        for (int i = 0; i < 9; i++) {

            //가로
            if (map[y][i] != 0) {
                exist[map[y][i]] = true;
            }

            //세로
            if (map[i][x] != 0) {
                exist[map[i][x]] = true;
            }
        }

        int smallY = (y / 3) * 3;
        int smallX = (x / 3) * 3;
        for (int i = smallY; i < smallY + 3; i++) {
            for (int j = smallX; j < smallX + 3; j++) {
                if (map[i][j] != 0) {
                    exist[map[i][j]] = true;
                }
            }
        }

        for (int number = 1; number <= 9; number++) {
            if (!exist[number]) {
                map[y][x] = number;
                game(idx + 1);
                map[y][x] = 0;
            }
        }
    }
}