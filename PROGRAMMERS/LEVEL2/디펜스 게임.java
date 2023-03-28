import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        int answer = 0;

        if (enemy.length <= k) {
            return enemy.length;
        }

        Queue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < k; i++) {
            pq.offer(enemy[i]);
            answer++;
        }

        int tmp = 0;

        for (int i = k; i < enemy.length; i++) {
            pq.offer(enemy[i]);

            int num = pq.poll();
            if (n < num) {
                break;
            }
            n -= num;
            answer++;
        }

        return answer;
    }
}