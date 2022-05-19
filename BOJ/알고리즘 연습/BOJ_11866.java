import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ_11866 {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		Queue<Integer> q = new LinkedList<>();
		
		for(int i=1;i<=n;i++) {
			q.offer(i);
		}
		
		solution(q,n,k);
		
		
	}
	
	static void solution(Queue<Integer> q, int n ,int k) {
		StringBuilder sb = new StringBuilder();
		sb.append("<");
		while(q.size()>0){
			for(int i=0;i<k-1;i++) {
				q.offer(q.poll());
			}
			sb.append(q.poll()).append(", ");
		}
		sb.delete(sb.length()-2, sb.length());
		sb.append(">");
		
		System.out.println(sb);
	}

}