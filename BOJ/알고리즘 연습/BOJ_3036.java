import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class BOJ_3036 {
	public static void main(String[] args) throws IOException {

		
		Scanner sc = new Scanner(System.in);
		
		int circle = sc.nextInt();
		
		int[] arr = new int[circle];
		
		for(int i=0;i<circle;i++) {
			arr[i]=sc.nextInt();
		}
		
		int first = arr[0];
		for(int i=1;i<circle;i++) {
			int compare = arr[i];
			
			int answer1 = first/gcd(first,compare);
			int answer2 = compare/gcd(first,compare);
			
			System.out.println(answer1+"/"+answer2);
		}
	}
	
	public static int gcd(int a, int b) {
		if(b==0) return a;
		else return gcd(b,a%b);
	}
}


