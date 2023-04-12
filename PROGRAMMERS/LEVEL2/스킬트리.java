import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;


        for (String skillTree : skill_trees) {
            int idx = 0;
            boolean ok = true;
            Queue<Character> q = new LinkedList<>();
            for (int i = 0; i < skillTree.length(); i++) {
                char st = skillTree.charAt(i);
                q.add(st);
                if(!skill.contains(String.valueOf(st))) {
                    q.poll();
                    continue;
                }
                if(st == skill.charAt(idx)) {
                    idx++;
                    q.poll();
                }
            }
            if(q.isEmpty()) {
                answer++;
            }

        }

        return answer;
    }
}