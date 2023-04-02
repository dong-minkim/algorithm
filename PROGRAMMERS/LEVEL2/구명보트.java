import java.util.Arrays;
import java.util.Collections;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);

        int standard = 0;

        for (int i = people.length - 1; i >= standard; i--) {
            if (people[standard] + people[i] <= limit) {
                answer++;
                standard++;
            } else {
                answer++;
            }
        }

        return answer;
    }
}