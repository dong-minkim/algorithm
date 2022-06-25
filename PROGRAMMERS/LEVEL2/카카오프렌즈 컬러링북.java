class Solution {
	static int M,N;
	static int[] dx= {1,-1,0,0};
	static int[] dy= {0,0,1,-1};
	
	public static int dfs(int y,int x,int[][] picture, boolean[][] visited) {
		int cnt=1;
		
		visited[y][x]=true;
		for(int i=0;i<4;i++) {
			int Y=y+dy[i];
			int X=x+dx[i];
			
			if(Y<0||Y>=M||X<0||X>=N) continue;
			if(visited[Y][X]==false && picture[y][x]==picture[Y][X]) {
				cnt += dfs(Y,X,picture,visited);
			}
		}
		return cnt;
	}
	
    public int[] solution(int m, int n, int[][] picture) {
    	M=m;
    	N=n;
    	
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        int[] answer = new int[2];
        boolean[][] visited = new boolean[m][n];
        
        for(int i=0;i<m;i++) {
        	for(int j=0;j<n;j++) {
        		if(picture[i][j]!=0 && visited[i][j]==false) {
        			numberOfArea++;
        			maxSizeOfOneArea = Math.max(maxSizeOfOneArea,dfs(i,j,picture,visited));
        		}
        	}
        }
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}