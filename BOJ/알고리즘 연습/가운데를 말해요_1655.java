import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder()); //(o1, o2) -> o2 - o1
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for(int i = 0 ; i < n; i++){
            int num = Integer.parseInt(br.readLine());

            if(minHeap.size() == maxHeap.size()) maxHeap.offer(num);
            else minHeap.offer(num);

            if(!minHeap.isEmpty() && !maxHeap.isEmpty())
                if(maxHeap.peek() > minHeap.peek()){
                    minHeap.add(maxHeap.poll());
                    maxHeap.add(minHeap.poll());
                }

            sb.append(maxHeap.peek() + "\n");
        }
        System.out.println(sb);
    }
}