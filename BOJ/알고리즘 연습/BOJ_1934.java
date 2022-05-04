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

public class BOJ_1934 {
	public static void main(String[] args) throws IOException {

		
		Scanner sc = new Scanner(System.in);
		
		int tc = sc.nextInt();
		
		while(tc-->0) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			System.out.println(a * b / gcd(a,b));
		}
		
	}
	
	public static int gcd(int a, int b) {
		if(b==0) return a;
		else return gcd(b,a % b);
	}
}


