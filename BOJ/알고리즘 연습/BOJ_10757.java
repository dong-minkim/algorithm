import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ_10757 {
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer str = new StringTokenizer(br.readLine());
		
		String firstStr = str.nextToken();
		String secondStr = str.nextToken();
		
		StringBuffer sb = new StringBuffer(firstStr);
		firstStr = sb.reverse().toString();
		
		sb = new StringBuffer(secondStr);
		secondStr = sb.reverse().toString();
		
		if(secondStr.length()>firstStr.length()) {
			String temp = firstStr;
			firstStr = secondStr;
			secondStr = temp;
		}
		
		int tmp = 0;
		String result = "";
		for(int i=0;i<secondStr.length();i++) {
			int num = (firstStr.charAt(i)-'0') + (secondStr.charAt(i)-'0');
			int temp = num + tmp;
			result += Integer.toString(temp%10);
			if(temp>9) tmp = 1;
			else tmp = 0;
		}
		
		if((secondStr.length() == firstStr.length()) && tmp!=0) {
			result += Integer.toString(tmp);
		}
		else {
			for(int i=secondStr.length();i<firstStr.length();i++) {
				int temp = (firstStr.charAt(i)-'0') + tmp;
				result+=Integer.toString(temp % 10);
				if(temp>9) tmp = 1;
				else tmp = 0;
			}
			if (tmp==1) result+="1";
		}
		
		
		sb = new StringBuffer(result);
		result = sb.reverse().toString();
		
		System.out.println(result);
		
		
	}
	
}
