import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {

    static int n, e;
    static List<Integer> dist;
    static final int INF = 200_000_000;
    static List<List<Node>> edge;
    static boolean[] visited;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        edge = Stream.generate(() -> new ArrayList<Node>())
                .limit(n + 1)
                .collect(Collectors.toList());

        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            edge.get(start).add(new Node(end, weight));
            edge.get(end).add(new Node(start, weight));
        }

        st = new StringTokenizer(br.readLine());
        int v1 = Integer.parseInt(st.nextToken());
        int v2 = Integer.parseInt(st.nextToken());

        int firstResult = 0;
        firstResult += dijkstra(1, v1);
        firstResult += dijkstra(v1, v2);
        firstResult += dijkstra(v2, n);

        int secondResult = 0;
        secondResult += dijkstra(1, v2);
        secondResult += dijkstra(v2, v1);
        secondResult += dijkstra(v1, n);

        if (firstResult >= INF || secondResult >= INF) {
            System.out.println(-1);
            return;
        }
        System.out.println(Math.min(firstResult, secondResult));
    }

    public static int dijkstra(int start, int end) {
        dist = Stream.generate(() -> INF)
                .limit(n + 1)
                .collect(Collectors.toList());

        visited = new boolean[n + 1];

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        dist.set(start, 0);

        while (!pq.isEmpty()) {
            Node tempNode = pq.poll();
            int currentNode = tempNode.end;

            if (visited[currentNode]) continue;
            visited[currentNode] = true;
            for (Node node : edge.get(currentNode)) {
                int nextNode = node.end;
                int nextWeight = node.weight;
                if (!visited[nextNode] && dist.get(nextNode) > dist.get(currentNode) + nextWeight) {
                    dist.set(nextNode, dist.get(currentNode) + nextWeight);
                    pq.offer(new Node(nextNode, dist.get(nextNode)));
                }
            }
        }
        return dist.get(end);
    }
}

class Node implements Comparable<Node> {
    int end;
    int weight;

    Node(int end, int weight) {
        this.end = end;
        this.weight = weight;
    }

    /*
     * 오름차순
     * */
    @Override
    public int compareTo(Node o) {
        return weight - o.weight;
    }
}