import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ_9020 {

	static boolean[] prime;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		prime = new boolean[10001];
		solution();
		
		int tc = Integer.parseInt(br.readLine());
		while(tc-->0) {
			int n = Integer.parseInt(br.readLine());
			int num1 = n/2;
			while(true) {
				int num2 = n - num1;
				if((!prime[num1])&&(!prime[num2])) {
					break;
				}
				num1--;
			}
			System.out.println(num1+" "+(n-num1));
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
