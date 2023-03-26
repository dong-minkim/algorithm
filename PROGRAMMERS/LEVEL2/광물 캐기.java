import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    /**
     * picks: dia, iron, stone
     */
    int fatigueWithDia = 0;
    int fatigueWithIron = 0;
    int fatigueWithStone = 0;
    List<int[]> fatigues = new ArrayList<>();
    ;

    public int solution(int[] picks, String[] minerals) {
        int answer = 0;

        int actions = minerals.length;
        if (minerals.length > Arrays.stream(picks).sum() * 5) {
            actions = Arrays.stream(picks).sum() * 5;
        }

        for (int i = 0; i < actions; i++) {
            fatigueWithDia++;
            fatigueWithIron++;
            fatigueWithStone++;

            if (minerals[i].equals("diamond")) {
                fatigueWithIron += 4;
                fatigueWithStone += 24;
            }
            if (minerals[i].equals("iron")) {
                fatigueWithStone += 4;
            }
            if ((i + 1) % 5 == 0 || (i + 1) == actions) {
                fatigues.add(new int[]{fatigueWithStone, fatigueWithIron, fatigueWithDia});
                fatigueWithDia = 0;
                fatigueWithIron = 0;
                fatigueWithStone = 0;
            }
        }

        Collections.sort(fatigues, (o1, o2) -> {
            if (o2[0] == o1[0]) {
                return o2[1] - o1[1];
            }
            return o2[0] - o1[0];
        });

        for (int i = 0, j = 0; i < picks.length; i++) {
            while (picks[i]-- > 0 && fatigues.size() > j) {
                if (i == 0) {
                    answer += fatigues.get(j)[2];
                } else if (i == 1) {
                    answer += fatigues.get(j)[1];
                } else {
                    answer += fatigues.get(j)[0];
                }
                j++;
            }
        }
        return answer;
    }
}