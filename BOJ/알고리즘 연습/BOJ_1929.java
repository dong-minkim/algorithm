import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ_1929 {

	static boolean[] prime;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());

		prime = new boolean[B + 1];
		solution();
		
		for(int i=A;i<=B;i++) {
			if(prime[i]==false) {
				System.out.println(i);
			}
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
