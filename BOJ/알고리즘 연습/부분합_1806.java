import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int s = scan.nextInt();

        int[] numbers = new int[n + 1];
        for (int i = 0; i < n; i++) {
            numbers[i] = scan.nextInt();
        }

        int start = 0, end = 0;
        int sum = 0;
        int min = Integer.MAX_VALUE;

        while (true) {
            if (sum >= s) {
                sum -= numbers[start++];
                min = Math.min(min, end - start + 1);
            }
            else if(end == n) break;
            else {
                sum += numbers[end++];
            }
        }

        if (min == Integer.MAX_VALUE) {
            System.out.println(0);
        }
        System.out.println(min);
    }
}
