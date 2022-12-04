import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[] maxDp = new int[3];
        int[] minDp = new int[3];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            int number1 = Integer.parseInt(st.nextToken());
            int number2 = Integer.parseInt(st.nextToken());
            int number3 = Integer.parseInt(st.nextToken());

            if (i == 0) {
                maxDp[0] = minDp[0] = number1;
                maxDp[1] = minDp[1] = number2;
                maxDp[2] = minDp[2] = number3;
            } else {

                int secondMaxDp = maxDp[1];
                maxDp[1] = Math.max(Math.max(maxDp[0], maxDp[1]), maxDp[2]) + number2;
                maxDp[0] = Math.max(maxDp[0], secondMaxDp) + number1;
                maxDp[2] = Math.max(secondMaxDp, maxDp[2]) + number3;

                int secondMinDp = minDp[1];
                minDp[1] = Math.min(Math.min(minDp[0], minDp[1]), minDp[2]) + number2;
                minDp[0] = Math.min(minDp[0], secondMinDp) + number1;
                minDp[2] = Math.min(secondMinDp, minDp[2]) + number3;
            }
        }

        System.out.print(Math.max(Math.max(maxDp[0], maxDp[1]), maxDp[2]) + " ");
        System.out.println(Math.min(Math.min(minDp[0], minDp[1]), minDp[2]));
        br.close();
    }
}