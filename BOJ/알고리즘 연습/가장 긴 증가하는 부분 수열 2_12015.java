import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        List<Integer> sequence = new ArrayList<>();
        sequence.add(0);
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int value = Integer.parseInt(st.nextToken());

            if (value > sequence.get(sequence.size() - 1)) {
                sequence.add(value);
            } else {
                int left = 0;
                int right = sequence.size() - 1;

                while (left < right) {
                    int mid = (left + right) / 2;
                    if (sequence.get(mid) >= value) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                sequence.set(left, value);
            }
        }

        System.out.println(sequence.size() - 1);
    }
}