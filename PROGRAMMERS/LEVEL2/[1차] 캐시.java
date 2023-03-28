import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;

        List<String> array = new ArrayList<>();

        if (cacheSize == 0) {
            return cities.length * 5;
        }

        for (int i = 0; i < cities.length; i++) {
            String city = cities[i].toLowerCase();

            if (array.contains(city)) {
                answer++;
                array.remove(city);
                array.add(city);
            } else {
                answer += 5;

                if (array.size() == cacheSize) {
                    array.remove(0);
                }

                array.add(city);
            }

        }

        return answer;
    }
}