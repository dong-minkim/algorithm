import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_2577
{
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcase = Integer.parseInt(br.readLine());
		
		while(testcase-->0) {
			String str = br.readLine();
			
			int cnt=0;
			int sum=0;
			for(int i=0;i<str.length();i++) {
				if(str.charAt(i)=='O') {
					cnt++;
					sum+=cnt;
				}
				else {
					cnt=0;
				}
			}
			
			System.out.println(sum);
			
		}
		
		
	}
}
