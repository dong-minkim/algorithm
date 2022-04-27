import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ_2581 {

	static boolean[] prime;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int A = Integer.parseInt(br.readLine());
		int B = Integer.parseInt(br.readLine());

		prime = new boolean[B + 1];
		solution();
		
		int sum=0;
		int min = 0;
		boolean flag = true;
		for(int i=A;i<=B;i++) {
			if(prime[i]==false) {
				sum+=i;
				if(flag) {
					min = i;
					flag = false;
				}
			}
		}
		if(sum==0) System.out.println(-1);
		else {
			System.out.println(sum);
			System.out.println(min);
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
