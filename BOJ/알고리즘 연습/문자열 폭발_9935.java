import java.io.*;

public class Main {
    static String str;
    static String boom;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        str = br.readLine();
        boom = br.readLine();

        for (int i = 0; i < str.length(); i++) {
            sb.append(str.charAt(i));
            if (sb.length() >= boom.length()) {
                boolean contain = true;

                for (int j = 0; j < boom.length(); j++) {
                    if (sb.charAt(sb.length() - boom.length() + j) != boom.charAt(j)) {
                        contain = false;
                        break;
                    }
                }
                if (contain) {
                    sb.delete(sb.length() - boom.length(), sb.length());
                }
            }
        }

        if (sb.length() == 0) {
            System.out.println("FRULA");
            return;
        }
        System.out.println(sb.toString());
    }
}