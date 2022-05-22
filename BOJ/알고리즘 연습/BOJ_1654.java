import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.Vector;

public class BOJ_1654 {
	public static void main(String[] args) throws IOException {
		
		Vector<Long> arr = new Vector<Long>();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		long k = Long.parseLong(st.nextToken());
		long n = Long.parseLong(st.nextToken());
		
		
		long left = 1;
		long right = 0;
		
		
		for(int i=0;i<k;i++) {
			long num = Long.parseLong(br.readLine());
			if(right<num) right = num;
			arr.add(num);
		}

		while(left<=right) {
			long sum = 0;
			long mid = (left+right) / 2;
			for(int i=0;i<arr.size();i++) {
				sum += (arr.get(i))/mid;
			}
			
			if(sum<n) right = mid - 1;
			else left = mid + 1;
		}
		
		System.out.println(right);

	}  
}


/*
static boolean binarySearch(int value, int left, int right) {
	while(left<=right) {
		int mid = (left + right) / 2;
		
		if(value == arr.get(mid)) return true;
		else if(value < arr.get(mid)) right=mid-1;
		else left = mid+1;
	}
	return false;
}
*/



