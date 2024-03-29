import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int n, long left, long right) {
        List<Long> list = new ArrayList<>();

        for (long i = left; i <= right; i++) {
            list.add(Math.max(i / n, i % n) + 1);
        }

        int[] answer = list.stream().mapToInt(i -> Math.toIntExact(i)).toArray();
        return answer;
    }
}