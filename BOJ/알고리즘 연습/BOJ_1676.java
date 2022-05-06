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

public class BOJ_1010 {
	public static void main(String[] args) throws IOException {
	
	Scanner sc = new Scanner(System.in);
	
	int num = sc.nextInt();
	int answer=0;
	
	while(num>0) {
		answer += num/5;
		num /=5;
	}
	
	System.out.println(answer);
	
	}
}
