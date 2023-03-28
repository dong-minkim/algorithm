import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public List<Integer> solution(int n, String[] words) {
        List<Integer> answer = new ArrayList<>();
        Set<String> tmp = new HashSet<>();

        tmp.add(words[0]);
        for (int i = 2; i <= words.length; i++) {
            tmp.add(words[i - 1]);
            if (tmp.size() != i || words[i - 1].charAt(0) != words[i - 2].charAt(words[i - 2].length() - 1)) {
                int userNum = i % n;
                if (userNum == 0) userNum = n;
                answer.add(userNum);
                answer.add((i - 1) / n + 1);
                return answer;
            }
        }
        answer.add(0);
        answer.add(0);

        return answer;
    }
}