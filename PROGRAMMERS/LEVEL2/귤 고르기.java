import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;

        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < tangerine.length; i++) {
            map.put(tangerine[i], map.getOrDefault(tangerine[i], 0) + 1);
        }

        List<Integer> keySet = new ArrayList<>(map.keySet());

        Collections.sort(keySet, (o1, o2) -> map.get(o2) - map.get(o1));

        int sum = 0;
        for (Integer key : keySet) {
            answer++;
            sum += map.get(key);

            if (sum >= k) {
                return answer;
            }
        }

        return answer;
    }
}