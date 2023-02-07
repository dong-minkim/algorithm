import java.util.*;

class Solution {
    public List<Integer> solution(String today, String[] terms, String[] privacies) {
        int answerCnt = 0;
        List<Integer> answer = new ArrayList<>();

        Map<String, Integer> map = new HashMap<>();
        StringTokenizer st;

        st = new StringTokenizer(today, ". ");
        int nowYear = Integer.parseInt(st.nextToken());
        int nowMonth = Integer.parseInt(st.nextToken());
        int nowDay = Integer.parseInt(st.nextToken());

        for (String term : terms) {
            st = new StringTokenizer(term, " ");
            map.put(st.nextToken(), Integer.parseInt(st.nextToken()));
        }

        for (String privacy : privacies) {
            answerCnt++;

            st = new StringTokenizer(privacy, ". ");
            int year = Integer.parseInt(st.nextToken());
            int month = Integer.parseInt(st.nextToken());
            int day = Integer.parseInt(st.nextToken());
            int plusTerm = map.get(st.nextToken());

            month += plusTerm;

            day--;
            if (day == 0) {
                day = 28;
                month--;
            }

            if (month > 12) {
                year += (month - 1) / 12;
                month = month % 12;
            }

            if (month == 0) month = 12;

            System.out.println(year + " " + month + " " + day + " || " + plusTerm);
            if (nowYear > year) {
                answer.add(answerCnt);
            } else if (nowYear == year && nowMonth > month) {
                answer.add(answerCnt);
            } else if (nowYear == year && nowMonth == month && nowDay > day) {
                answer.add(answerCnt);
            }
        }
        Collections.sort(answer);
        return answer;
    }
}
