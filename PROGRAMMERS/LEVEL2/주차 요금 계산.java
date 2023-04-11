import java.util.*;

class Solution {
    public List solution(int[] fees, String[] records) {
        List<Integer> answer = new ArrayList<>();

        Map<String, Integer> park = new HashMap<>();
        Map<String, Integer> result = new HashMap<>();
        for (String record : records) {
            String[] str = record.split(" |:");

            int time = Integer.parseInt(str[0]) * 60 + Integer.parseInt(str[1]);

            if ("IN".equals(str[3])) {
                park.put(str[2], time);
            }

            if ("OUT".equals(str[3])) {
                result.put(str[2], result.getOrDefault(str[2], 0) + (time - park.get(str[2])));
                park.remove(str[2]);
            }
        }

        if (!park.isEmpty()) {
            for (String key : park.keySet()) {
                result.put(key, result.getOrDefault(key, 0) + ((23 * 60 + 59) - park.get(key)));
            }
        }

        for (String key : result.keySet()) {
            int payment = 0;
            payment += fees[1];
            if (result.get(key) > fees[0]) {
                payment += Math.ceil((result.get(key) - fees[0]) / (double) fees[2]) * fees[3];
            }
            result.put(key, payment);
        }

        List<String> keySet = new ArrayList<>(result.keySet());
        Collections.sort(keySet);

        for (String key : keySet) {
            answer.add(result.get(key));
        }

        return answer;
    }
}