import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.Vector;

public class BOJ_10816 {

	static Vector<Integer> arr = new Vector<Integer>();
	
	public static void main(String[] args) throws IOException {
		
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			arr.add(Integer.parseInt(st.nextToken()));
		}
		
		Collections.sort(arr);
		
		n= Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int tmp = Integer.parseInt(st.nextToken());
			int result = upperBound(arr, tmp) -
					lowerBound(arr, tmp);
			sb.append(result).append(" ");
		}
		System.out.println(sb);
	}  
	
	static int lowerBound(Vector<Integer> v, int value) {
		int left = 0;
		int right = v.size();
		while(left<right) {
			int mid = (left + right) / 2;
			
			if(value <= v.get(mid)) {
				right = mid;
			}
			else left = mid + 1;
		}
		return right;
	}
	
	static int upperBound(Vector<Integer> v, int value) {
		int left = 0;
		int right = v.size();
		while(left<right) {
			int mid = (left + right) / 2;
			
			if(value >= v.get(mid)) {
				left = mid + 1;
			}
			else right = mid;
		}
		return right;
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