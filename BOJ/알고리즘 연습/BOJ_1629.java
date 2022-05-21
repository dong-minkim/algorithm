import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ_1629 {

	
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		long a = Long.parseLong(st.nextToken());
		long b = Long.parseLong(st.nextToken());
		long c = Long.parseLong(st.nextToken());
		
		long result = solution(a,b,c) % c;
		
		System.out.println(result);
		
	}
	
	static long solution(long a,long b,long c) {
		if(b==1) return a%c;
		else if(b%2==0) { //Â¦¼ö
			long tmp = solution(a,b/2,c) % c;
			return (tmp * tmp) % c;
		}
		else {
			long tmp = solution(a,b/2,c) % c;
			return (((tmp * tmp) % c ) * a ) % c;
		}
	}

}