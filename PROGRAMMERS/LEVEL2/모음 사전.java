class Solution {
    public int solution(String word) {

        String alphabet = "AEIOU";
        int[] digitValue = {781, 156, 31, 6, 1};

        int answer = word.length();

        for (int i = 0; i < word.length(); i++) {
            answer += alphabet.indexOf(word.charAt(i)) * digitValue[i];
        }

        return answer;
    }
}