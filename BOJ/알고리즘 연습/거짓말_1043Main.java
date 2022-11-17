import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[] truths;
    static int[] parent;
    static List<int[]> parties = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int answer = 0;

        st = new StringTokenizer(br.readLine());
        int truthSize = Integer.parseInt(st.nextToken());
        if (truthSize == 0) {
            System.out.println(M);
            return;
        }

        truths = new int[truthSize];
        for (int i = 0; i < truthSize; i++) {
            truths[i] = Integer.parseInt(st.nextToken());
        }

        parent = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        /*
         * 파티 탐색
         * */
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int partySize = Integer.parseInt(st.nextToken());
            int[] peopleInParty = new int[partySize];
            int firstPeopleInParty = Integer.parseInt(st.nextToken());
            peopleInParty[0] = firstPeopleInParty;

            for (int j = 1; j < partySize; j++) {
                int otherPeople = Integer.parseInt(st.nextToken());
                peopleInParty[j] = otherPeople;

                /*
                 * 더 작은 수가 부모가 되도록
                 * */
                if (firstPeopleInParty < peopleInParty[j]) {
                    union(firstPeopleInParty, otherPeople);
                } else union(otherPeople, firstPeopleInParty);
            }
            parties.add(peopleInParty);
        }

        for (int[] party : parties) {
            boolean hasKnowingInParty = false;
            for (int person : party) {
                hasKnowingInParty = check(person);
                if(hasKnowingInParty == true) break;
            }
            if (!hasKnowingInParty) answer++;
        }
        System.out.println(answer);
    }

    static public int find(int a) {
        if (a == parent[a]) return a;
        else return parent[a] = find(parent[a]);
    }

    static public void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            parent[b] = a;
        }
    }

    static public boolean check(int a) {
        a = find(a);
        for (int truth : truths) {
            if (a == find(truth)) {
                return true;
            }
        }
        return false;
    }
}