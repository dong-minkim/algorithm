import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        long[] arr = new long[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(arr);

        long min = Long.MAX_VALUE;
        int left, mid, right;
        int resultLeft = 0, resultRight = 0, resultMid = 0;

        for (int i = 0; i < n - 2; i++) {
            left = i;
            mid = i + 1;
            right = n - 1;
            while (mid < right) {
                long sum = arr[left] + arr[mid] + arr[right];
                if (min > Math.abs(sum)) {
                    min = Math.abs(sum);
                    resultLeft = left;
                    resultMid = mid;
                    resultRight = right;
                }
                if (sum == 0) {
                    break;
                } else if (sum > 0) {
                    right--;
                } else {
                    mid++;
                }
            }
        }
        System.out.println(arr[resultLeft] + " " + arr[resultMid] + " " + arr[resultRight]);
    }
}