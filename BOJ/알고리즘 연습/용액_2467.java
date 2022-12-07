import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        long[] arr = new long[n + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        long min = Long.MAX_VALUE;
        int left = 0, right = n - 1;
        int resultLeft = 0, resultRight = 0;
        while (left < right) {
            long sum = arr[left] + arr[right];
            if (min > Math.abs(sum)) {
                min = Math.abs(sum);
                resultLeft = left;
                resultRight = right;
            }
            if (sum >= 0) {
                right--;
            } else {
                left++;
            }
        }
        System.out.println(arr[resultLeft] + " " + arr[resultRight]);
    }
}