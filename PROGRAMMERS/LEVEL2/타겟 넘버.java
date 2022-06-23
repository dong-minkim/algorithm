class Solution {
	
	static int answer=0;
	
	static void dfs(int[] numbers, int target, int sum, int cnt) {
		if(cnt == numbers.length) {
			if(target==sum) answer++;
			return;
		}
		
		dfs(numbers,target,sum + numbers[cnt], cnt+1);
		dfs(numbers,target,sum - numbers[cnt], cnt+1);
		
	}
	
    public int solution(int[] numbers, int target) {
    	dfs(numbers,target,0,0);
    	
        return answer;
    }   
}