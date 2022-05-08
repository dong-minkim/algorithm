import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;

public class BOJ_1003 {
	
	static int[] cnt = new int[41];

	public static void main(String[] args) throws IOException {

		cnt[1]=1;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		StringBuilder sb = new StringBuilder();
		
		for(int i=0;i<T;i++) {
			int n = Integer.parseInt(br.readLine());
			
			if (n==0) sb.append(1).append(" ").append(0).append('\n');
			else sb.append(fibo(n-1)).append(" ").append(fibo(n)).append('\n');
		}
		System.out.println(sb);
	}
	
	public static int fibo(int n) {
		if(n==0 || n==1) return cnt[n];
		else if(cnt[n]==0) {
			cnt[n]=fibo(n-1) + fibo(n-2);
		}
		return cnt[n];
	}
}
