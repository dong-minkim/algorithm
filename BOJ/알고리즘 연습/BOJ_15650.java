import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;

public class BOJ_15650 {

	static Vector<Integer> v = new Vector<Integer>();
	static int[] check = new int[9];
	static int n = 0;
	static int m = 0;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		solution(0, 0);
		
	}
	
	static void solution(int index, int x) {
		
		if(x==m) {
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < m ;i++) {
				sb.append(v.get(i)).append(" ");
			}
			System.out.println(sb);
			return;
		}
		for (int i = index + 1; i <= n; i++) {
			if (check[i]==0) {
				check[i] = 1;
				v.add(i);
				solution(i, x + 1);
				check[i] = 0;
				v.remove(v.size()-1);
			}
		}
	}
}
