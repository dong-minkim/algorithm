import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int length = scan.nextInt();
        int testCase = scan.nextInt();

        int y_length = length;
        int x_length = length;

        while (testCase-- > 0) {
            int y = scan.nextInt();
            int x = scan.nextInt();
            if (y > y_length || x > x_length) continue;

            int tmp_y = y;
            int tmp_x = x_length;
            int weight = y * x_length;

            if (weight < y_length * x) {
                tmp_y = y_length;
                tmp_x = x;
            }

            y_length = tmp_y;
            x_length = tmp_x;
        }

        System.out.println(y_length * x_length);

        scan.close();
    }
}
