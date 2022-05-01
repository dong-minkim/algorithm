import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ_4948 {

	static boolean[] prime;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		prime = new boolean[123456*2+1];
		solution();
		
		while (true){
			
			int n = Integer.parseInt(br.readLine());
			if(n==0) break;
			
			int cnt = 0;
			
			for(int i=n+1;i<=2*n;i++) {
				if(prime[i]==false) {
					cnt++;
				}
			}
			System.out.println(cnt);
		} 

		
	}

	public static void solution() {
		prime[1] = true;  //true: 소수가 아니다.

		for (int i = 2; i <= Math.sqrt(prime.length); i++) {
			if (prime[i]) continue;
			
			//i 배수 소수 아님 처리
			for (int j = i * i; j < prime.length; j += i) {
				 prime[j]=true;
			}
		}
	}
}
