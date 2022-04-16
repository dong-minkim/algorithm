import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class BOJ_2577{
	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);
		
		int testcase = sc.nextInt();
		
		while(testcase-->0) {
			int stuNum = sc.nextInt();
			double sum=0;
			double[] stuScore = new double[stuNum];
			
			for(int i=0;i<stuNum;i++) {
				stuScore[i] = sc.nextDouble();
				sum+=stuScore[i];
			}
			double avg = sum/stuNum;
			
			double cnt = 0;
			for(int i=0;i<stuNum;i++) {
				if(avg<stuScore[i]) cnt++;
			}
			
			System.out.println(String.format("%.3f", cnt/stuNum * 100 )+"%");
			
		}
		
	}
}
