import java.util.*;

public class Main {

    static List<List<Node>> edge = new ArrayList<>();
    static boolean[] visited;
    static int max = Integer.MIN_VALUE;
    static int farNode;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int v = scan.nextInt();
        edge.add(new ArrayList<Node>());
        for (int i = 1; i <= v; i++) {
            edge.add(new ArrayList<Node>());
        }
        for (int i = 1; i <= v; i++) {
            int curNode = scan.nextInt();
            while (true) {
                int nextNode = scan.nextInt();
                if (nextNode == -1) {
                    break;
                }
                int nextCost = scan.nextInt();
                edge.get(curNode).add(new Node(nextNode, nextCost));
            }
        }

        visited = new boolean[v + 1];
        dfs(1, 0);

        visited = new boolean[v + 1];
        dfs(farNode, 0);

        System.out.println(max);
    }

    static void dfs(int node, int length) {
        if (length > max) {
            max = length;
            farNode = node;
        }

        visited[node] = true;

        for (Node curNode : edge.get(node)) {
            int nextNode = curNode.node;
            int nextDist = curNode.cost;
            if (visited[nextNode] == true) continue;
            dfs(nextNode, nextDist + length);
            visited[nextNode] = true;
        }
    }

    static class Node {
        int node;
        int cost;

        public Node(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }
    }
}