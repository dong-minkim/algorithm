import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_2941 {
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str = br.readLine();
		
		int cnt = 1;
		
		for(int i=1;i<str.length();i++) {
			cnt++;
			if(str.charAt(i)=='=') {
				cnt--;
				if(i!=1 && str.charAt(i-1)=='z' && str.charAt(i-2)=='d') cnt--;
			}
			else if(str.charAt(i)=='j' && (str.charAt(i-1)=='l'||str.charAt(i-1)=='n')) cnt--;
			else if(str.charAt(i)=='-') cnt--;
				
		}
		
		System.out.println(cnt);
	}
	
}
