import java.util.*;
import java.util.Map.Entry;

class Solution {

	int[] lion;
	int[] answer = {-1,};
	int maxValue = Integer.MIN_VALUE;

	public void dfs(int cnt, int total, int[] info) {
		if(cnt==total) {
			int apeachSum=0;
			int lionSum=0;
			for(int i=0;i<=10;i++) {
				if(info[i]==0 && lion[i]==0) continue;
				if(info[i]<lion[i]) lionSum += (10 - i);
				else apeachSum += (10 - i);
			}
			
			if(lionSum>apeachSum) {
				int tmp = lionSum - apeachSum;
				if(tmp>=maxValue) {
					maxValue = tmp;
					answer = lion.clone();
				}
			}
			return;
		}
		for(int i=0;i<=10 && lion[i]<=info[i];i++) {
			lion[i]++;
			dfs(cnt+1,total,info);
			lion[i]--;
		}
	}

	public int[] solution(int total, int[] info) {

		lion = new int[11];

		dfs(0, total, info);
		
		return answer;
	}
}
