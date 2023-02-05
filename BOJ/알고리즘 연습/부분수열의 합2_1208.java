import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, S;
    static int[] arr;
    static List<Integer> leftList = new ArrayList<>();
    static List<Integer> rightList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        arr = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        makeSumList(0, N / 2, 0, leftList);
        makeSumList(N / 2, N, 0, rightList);

        Collections.sort(leftList);
        Collections.sort(rightList);

        if (S == 0) System.out.println(getAnswer() - 1);
        else System.out.println(getAnswer());
    }

    public static long getAnswer() {
        long cnt = 0;

        int left = 0;
        int right = rightList.size() - 1;

        while (left < leftList.size() && 0 <= right) {
            int leftValue = leftList.get(left);
            int rightValue = rightList.get(right);
            int sum = leftValue + rightValue;

            if (S == sum) {
                long leftCnt = 0;
                long rightCnt = 0;

                //중복되는 수 카운트
                while (left < leftList.size() && leftList.get(left) == leftValue) {
                    left++;
                    leftCnt++;
                }

                while (0 <= right && rightList.get(right) == rightValue) {
                    right--;
                    rightCnt++;
                }

                cnt += leftCnt * rightCnt;
            }

            if (sum < S) {
                left++;
            }

            if (sum > S) {
                right--;
            }
        }
        return cnt;
    }

    public static void makeSumList(int index, int end, int sum, List<Integer> list) {
        if (index == end) {
            list.add(sum);
            return;
        }
        makeSumList(index + 1, end, sum, list);
        makeSumList(index + 1, end, sum + arr[index], list);
    }
}