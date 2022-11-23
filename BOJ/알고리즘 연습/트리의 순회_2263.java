import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int size;

    public static int[] inOrder;
    public static int[] inOrderIndex; // 중위 순회에 루트들의 인덱스 정보를 입력한다.
    public static int[] postOrder;

    public static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        size = Integer.parseInt(br.readLine());

        inOrder = new int[size + 1];
        inOrderIndex = new int[size + 1];
        postOrder = new int[size + 1];

        sb = new StringBuilder();


        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= size; i++) {
            inOrder[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= size; i++) {
            postOrder[i] = Integer.parseInt(st.nextToken());
        }

        // 중위순회에 노드들이 루트일경우 인덱스 정보를 저장
        for (int i = 1; i <= size; i++) {
            inOrderIndex[inOrder[i]] = i;
        }

        getPreOrder(1, size, 1, size);
        System.out.println(sb.toString());
    }

    public static void getPreOrder(int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd) {
        // 중위, 후위 준회의 시작점은 종료점 보다 크면 안된다.
        if (inOrderStart > inOrderEnd || postOrderStart > postOrderEnd) return;

        // 루트를 구한다. 후위 순회의 마지막 인덱스 poO_end가 루트의 인덱스이다.
        int root = postOrder[postOrderEnd];
        sb.append(root + " ");

        // 중위 순회에서 루트의 인덱스를 알아온다.
        int rootIdx = inOrderIndex[root];
        // 중위 순회에서 루트 기준 왼쪽에 몇개가 있는지 계산한다.
        int left = rootIdx - inOrderStart;

        //좌측 자식 노드들을 구한다.
        getPreOrder(inOrderStart, rootIdx - 1, postOrderStart, postOrderStart + left - 1);

        // 우측 자식 노드들을 구한다.
        getPreOrder(rootIdx + 1, inOrderEnd, postOrderStart + left, postOrderEnd - 1);
    }
}
