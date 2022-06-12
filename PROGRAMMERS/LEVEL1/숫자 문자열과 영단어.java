class Solution {
    public int solution(String s) {
        String answer = "";
        for(int i = 0; i < s.length(); i++){
        if(s.charAt(i) >= '0' && s.charAt(i) <= '9'){
            answer += s.charAt(i);
        }
        else{
            if(s.charAt(i) == 'z'){
                answer += '0';
                i += 3;
            }
            else if(s.charAt(i) == 'o'){
                answer += '1';
                i += 2;
            }
            else if(s.charAt(i) == 't'){
                if(s.substring(i, i+3).equals("two")){
                    answer += '2';
                    i += 2;
                }
                else{
                    answer += '3';
                    i += 4;
                }
            }
            else if(s.charAt(i) == 'f'){
                if(s.substring(i, i+4).equals("four")){
                    answer += '4';
                }
                else{
                    answer += '5';
                }
                i += 3;
            }
            else if(s.charAt(i) == 's'){
                if(s.substring(i, i+3).equals("six")){
                    answer += '6';
                    i += 2;
                }
                else{
                    answer += '7';
                    i += 4;
                }
            }
            else if(s.charAt(i) == 'e'){
                answer += '8';
                i += 4;
            }
            else if(s.charAt(i) == 'n'){
                answer += '9';
                i += 3;
            }
        }
    }
        
        return Integer.parseInt(answer);
    }
}