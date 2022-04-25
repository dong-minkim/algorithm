import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2231 {

	static boolean[] prime;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int i;
		for (i = 1; i <= n; i++) {

			int sum = i;
			int tmp = i;
			while (true) {

				sum += tmp % 10;
				if (tmp < 10) {
					break;
				}
				tmp /= 10;
			}

			if (sum == n) {
				System.out.println(i);
				return;
			}

			if (i == n) {
				System.out.println(0);
			}
		}

	}

}
