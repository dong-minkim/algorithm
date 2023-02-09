import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Solution {
    static String[][] map = new String[51][51];
    static int[][] area = new int[51][51];
    static List<String> answer = new ArrayList<>();

    public List<String> solution(String[] commands) {

        init();

        for (String command : commands) {
            activate(command);
        }
        return answer;
    }

    static void init() {
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                map[i][j] = "EMPTY";
                area[i][j] = (i - 1) * 50 + j;
            }
        }
    }

    static void activate(String command) {
        StringTokenizer st = new StringTokenizer(command);

        if (st.countTokens() == 3) {
            String com = st.nextToken();

            if (com.equals("UPDATE")) {
                String value1 = st.nextToken();
                String value2 = st.nextToken();
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        if (map[i][j].equals(value1)) {
                            map[i][j] = value2;
                        }
                    }
                }
            }
            if (com.equals("UNMERGE")) {
                int r = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                int tmpArea = area[r][c];
                String tmpStr = map[r][c];
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        if (area[i][j] == tmpArea) {
                            area[i][j] = (i - 1) * 50 + j;
                            map[i][j] = "EMPTY";
                        }
                    }
                }
                map[r][c] = tmpStr;
            }
            if (com.equals("PRINT")) {
                int r = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                answer.add(map[r][c]);
            }
        }

        //UPDATE r c value
        if (st.countTokens() == 4) {
            st.nextToken();
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            String value = st.nextToken();

            int tmpArea = area[r][c];
            for (int i = 1; i <= 50; i++) {
                for (int j = 1; j <= 50; j++) {
                    if (area[i][j] == tmpArea) {
                        map[i][j] = value;
                    }
                }
            }

        }

        //MERGE r1 c1 r2 c2 -> (r1, c1)에 병합
        if (st.countTokens() == 5) {
            st.nextToken();
            int r1 = Integer.parseInt(st.nextToken());
            int c1 = Integer.parseInt(st.nextToken());
            int r2 = Integer.parseInt(st.nextToken());
            int c2 = Integer.parseInt(st.nextToken());

            String mapValue1 = map[r1][c1];
            String mapValue2 = map[r2][c2];

            int tmpArea1 = area[r1][c1];
            int tmpArea2 = area[r2][c2];

            int standardArea;
            int opponentArea;
            String standardValue;

            if(mapValue1.equals("EMPTY")) {
                opponentArea = tmpArea1;
                standardArea = tmpArea2;
                standardValue = mapValue2;
            } else {
                opponentArea = tmpArea2;
                standardArea = tmpArea1;
                standardValue = mapValue1;
            }

            for (int i = 1; i <= 50; i++) {
                for (int j = 1; j <= 50; j++) {
                    if (opponentArea == area[i][j]) {
                        area[i][j] = standardArea;
                        map[i][j] = standardValue;
                    }
                }
            }
        }
    }
}