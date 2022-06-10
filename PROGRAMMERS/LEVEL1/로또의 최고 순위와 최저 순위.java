class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        
        int[] answer = {0,0};
        
        int rankMax = 0;
        int rankMin = 0;
        
        for(int i=0;i<6;i++) {
        	if(lottos[i]==0) {
        		rankMax++;
        		continue;
        	}
        	for(int j=0;j<6;j++) {
        		if(lottos[i]==win_nums[j]) {
        			rankMax++;
        			rankMin++;
        		}
        	}
        }
        
        int result = 7 - rankMax;
        if(result>=6) result = 6;
        answer[0] = result;
        
        result = 7 - rankMin;
        if(result>=6) result = 6;
        answer[1] = result;
        
        return answer;
    }
}