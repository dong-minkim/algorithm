import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    public String[] solution(String[] files) {

        Arrays.sort(files, (o1, o2) -> {
            String[] str1 = part(o1);
            String[] str2 = part(o2);

            if (str1[0].equals(str2[0])) {
                return Integer.parseInt(str1[1]) - Integer.parseInt(str2[1]);
            }
            return str1[0].compareTo(str2[0]);
        });

        return files;
    }

    String[] part(String str) {
        String[] part = new String[3];
        String HEAD = "";
        String NUMBER = "";

        boolean isHead = true;
        for (int i = 0; i < str.length(); i++) {

            // HEAD
            if (isHead && !Character.isDigit(str.charAt(i))) {
                HEAD += str.charAt(i);
            } else if (isHead && Character.isDigit(str.charAt(i))) {
                isHead = false;
                NUMBER += str.charAt(i);

            // NUMBER
            } else if (Character.isDigit(str.charAt(i)) && NUMBER.length() < 5) {
                NUMBER += str.charAt(i);

            // TAIL
            } else {
                part[0] = HEAD.toLowerCase();
                part[1] = NUMBER;
                part[2] = str.substring(i);
                return part;
            }
        }
        // 만약 NUMBER로 끝날 경우
        part[0] = HEAD.toLowerCase();
        part[1] = NUMBER;
        part[2] = "";
        return part;
    }
}