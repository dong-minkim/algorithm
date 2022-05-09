import java.io.BufferedInputStream;
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

public class BOJ_2004 {
	public static void main(String[] args) throws IOException {
	
	Scanner sc = new Scanner(System.in);
	
	int a = sc.nextInt();
	int b = sc.nextInt();
	int c = a-b;
	
	int d=a;
	int e=b;
	int f=c;
	int answer1=0;
	int answer2=0;
	int answer3=0;
	int answer4=0;
	
	while(a>0) {
		answer1 += a/5;
		a /=5;
	}
	
	while(d>0) {
		answer3 += d/2;
		d /=2;
	}
	
	while(b>0) {
		answer2 += b/5;
		b /=5;
	}
	
	while(e>0) {
		answer4 += e/2;
		e /=2;
	}
	
	while(c>0) {
		answer2 += c/5;
		c /=5;
	}
	
	while(f>0) {
		answer4 += f/2;
		f /=2;
	}
	
	
	System.out.println(Math.min(answer1-answer2, answer3-answer4));
	
	}
}
