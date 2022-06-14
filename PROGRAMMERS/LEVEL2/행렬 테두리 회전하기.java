class Solution {
	static int[][] map;
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        map = new int[rows][columns];
        int init = 1;
        for(int i=0;i<rows;i++) {
        	for(int j=0;j<columns;j++) {
        		map[i][j] = init++;
        	}
        }
        
        
        for(int i=0;i<queries.length;i++) {
        	int[] query = queries[i];
        	
        	int x=query[0]-1, y=query[1]-1,
        		z=query[2]-1, r=query[3]-1;
        	
        	answer[i]=rotation(x,y,z,r);
        }
        return answer;
    }
    
    static int rotation(int x, int y, int z, int r) {
    	
    	int tmp = map[x][r];
    	int min = tmp;
    	
    	for(int a=r-1;a>=y;a--) {
    		min = Math.min(min, map[x][a]);
    		map[x][a+1] = map[x][a];
    	}
    	for(int b=x+1;b<=z;b++) {
    		min = Math.min(min, map[b][y]);
    		map[b-1][y] = map[b][y];
    	}
    	for(int a=y+1;a<=r;a++) {
    		min = Math.min(min, map[z][a]);
    		map[z][a-1] = map[z][a];
    	}
    	for(int b=z-1;b>=x;b--) {
    		min = Math.min(min, map[b][r]);
    		map[b+1][r] = map[b][r];
    	}
    	
    	map[x+1][r] = tmp;
    	
    	return min;
    }
}