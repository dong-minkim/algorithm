class Solution {
    static int[] answer = {0, 0};
    static int[] discounts = {10, 20, 30, 40};

    public int[] solution(int[][] users, int[] emoticons) {

        int[] tmp = new int[emoticons.length];

        dfs(0, tmp, users, emoticons);
        return answer;
    }

    static void dfs(int depth, int[] cases, int[][] users, int[] emoticons) {
        if (depth == emoticons.length) {
            int plusUser = 0;
            int totalCost = 0;

            for (int i = 0; i < users.length; i++) {
                int cost = 0;
                for (int j = 0; j < emoticons.length; j++) {
                    if (users[i][0] <= cases[j]) {
                        cost += emoticons[j] * (100 - cases[j]) / 100;
                    }
                }

                if (cost >= users[i][1]) {
                    plusUser++;
                } else {
                    totalCost += cost;
                }
            }

            if (plusUser > answer[0]) {
                answer[0] = plusUser;
                answer[1] = totalCost;
            } else if (plusUser == answer[0] && totalCost > answer[1]) {
                answer[1] = totalCost;
            }
            return;
        }

        for (int i = 0; i < discounts.length; i++) {
            cases[depth] = discounts[i];
            dfs(depth + 1, cases, users, emoticons);
        }
    }
}