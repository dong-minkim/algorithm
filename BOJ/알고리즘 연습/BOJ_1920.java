import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ_1629 {

	static ArrayList<Integer> arr = new ArrayList<Integer>();
	
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
			sb.append(binarySearch(Integer.parseInt(st.nextToken()),0,arr.size()-1)).append("\n");
		}
		System.out.println(sb);
	}
	
	static int binarySearch(int value, int left, int right) {
		while(left<=right) {
			int mid = (left + right) / 2;
			
			if(value == arr.get(mid)) return 1;
			else if(value < arr.get(mid)) right=mid-1;
			else left = mid+1;
		}
		return 0;
		
	}

}