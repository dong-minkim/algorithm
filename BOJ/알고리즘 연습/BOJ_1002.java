import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ_1002 {

	static boolean[] prime;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int tc = Integer.parseInt(br.readLine());

		while (tc-- > 0) {

			StringTokenizer st = new StringTokenizer(br.readLine());

			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int r1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			int r2 = Integer.parseInt(st.nextToken());
			
			int r3 = (int)Math.pow(r1+r2, 2);
			int r4 = (int)Math.pow(r1-r2, 2);
			
			int d = (int) (Math.pow(x1 - x2, 2) +  Math.pow(y1 - y2, 2));
			if (d == 0) {
				if (r1 == r2)
					System.out.println(-1);
				else
					System.out.println(0);

				continue;
			}
			
			if (r3 == d || r4 == d)
				System.out.println(1);
			else if (r3 > d && d > r4 )
				System.out.println(2);
			else
				System.out.println(0);
		}

	}
}
