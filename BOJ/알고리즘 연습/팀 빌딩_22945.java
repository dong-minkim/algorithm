import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        List<Integer> programmers = new ArrayList<>();
        Scanner scan = new Scanner(System.in);
        int answer = 0;

        int size = scan.nextInt();
        for (int i = 0; i < size; i++) {
            int programmer = scan.nextInt();
            programmers.add(programmer);
        }

        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int min = Math.min(programmers.get(left), programmers.get(right));
            answer = Math.max(min * (right - left - 1), answer);
            if (programmers.get(left) < programmers.get(right)) {
                left++;
                continue;
            }
            right--;
        }
        System.out.println(answer);

        scan.close();
    }
}
