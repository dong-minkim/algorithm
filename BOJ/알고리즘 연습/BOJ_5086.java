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

public class BOJ_5086 {
	public static void main(String[] args) throws IOException {

		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while(true) {
			
			boolean flag = true;
			
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
			if(n==0 && m==0) {
				break;
			}
			
			if(n>m) {
				flag = false;
				int tmp=0;
				tmp=n;
				n=m;
				m=tmp;
			}
			
			if(m%n==0) {
				if(flag==true) System.out.println("factor");
				else System.out.println("multiple");
			}
			else System.out.println("neither");
			
		}
		
	}
}


