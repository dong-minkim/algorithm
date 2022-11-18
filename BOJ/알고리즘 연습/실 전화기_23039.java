import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<int[]> edges = new ArrayList<>();
        Map<String, List<int[]>> cross = Map.of(
                "[1, 3]", List.of(new int[]{2, 4}, new int[]{2, 5}),
                "[1, 4]", List.of(new int[]{2, 5}, new int[]{3, 5}),
                "[2, 4]", List.of(new int[]{1, 3}, new int[]{3, 5}),
                "[2, 5]", List.of(new int[]{1, 3}, new int[]{1, 4}),
                "[3, 5]", List.of(new int[]{1, 4}, new int[]{2, 4}));
        Set<String> collisions = new HashSet<>();
        int[] rabbits = {0, 0, 0, 0, 0};

        Scanner scan = new Scanner(System.in);

        int edgeSize = scan.nextInt();
        for (int i = 0; i < edgeSize; i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();

            if (a > b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            edges.add(new int[]{a, b});
        }

        if (edgeSize == 10) {
            System.out.println(-1);
            return;
        }

        for (int[] edge : edges) {
            if (cross.containsKey(Arrays.toString(edge))) {
                for (int[] otherEdge : cross.get(Arrays.toString(edge))) {
                    for (int i = 0; i < edges.size(); i++) {
                        if (edges.get(i)[0] == otherEdge[0] && edges.get(i)[1] == otherEdge[1]) {
                            collisions.add(Arrays.toString(new int[]{edge[0], edge[1], otherEdge[0], otherEdge[1]}));
                            collisions.add(Arrays.toString(new int[]{otherEdge[0], otherEdge[1], edge[0], edge[1]}));
                            rabbits[edge[0]-1]++;
                            rabbits[edge[1]-1]++;

                        }
                    }
                }
            }
        }
        int collisionCnt = collisions.size() / 2;
        int maxCollisionRabbitCnt = Arrays.stream(rabbits).max().getAsInt();

        if (collisionCnt == 0) {
            System.out.println(0);
            return;
        }
        if (collisionCnt == maxCollisionRabbitCnt) {
            System.out.println(1);
            return;
        }
        System.out.println(2);
        scan.close();
    }
}
