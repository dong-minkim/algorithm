import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        
        for(int i=0;i<moves.length;i++) {
        	for(int j=0;j<board.length;j++) {
        		int tmp = board[j][moves[i]-1];
        		
        		if(tmp != 0) {
        			if(stack.peek()==tmp) {
        				answer+=2;
        				stack.pop();
        				board[j][moves[i]-1]=0;
        				break;
        			}
        			else {
            			stack.push(tmp);
            		}
            		board[j][moves[i]-1]=0;
    				break;
        		}
        	}
        }
        
        return answer;
    }
}