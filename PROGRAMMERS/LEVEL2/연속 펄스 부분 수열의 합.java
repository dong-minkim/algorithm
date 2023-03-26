import java.util.ArrayList;
import java.util.List;

class Solution {
    public long solution(int[] sequence) {
        long answer = 0;

        List<Long> positivePulse = new ArrayList<>();
        List<Long> negativePulse = new ArrayList<>();

        positivePulse.add(Long.valueOf(sequence[0]));
        negativePulse.add(Long.valueOf(-sequence[0]));
        answer = Math.max(positivePulse.get(0), negativePulse.get(0));

        for (int i = 1; i < sequence.length; i++) {
            positivePulse.add(Math.max(sequence[i], negativePulse.get(i - 1) + sequence[i]));
            negativePulse.add(Math.max(-sequence[i], positivePulse.get(i - 1) - sequence[i]));
            answer = Math.max(answer, Math.max(positivePulse.get(i), negativePulse.get(i)));
        }

        return answer;
    }

}