import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        char[] calculation = scan.nextLine().toCharArray();
        Stack<Character> op = new Stack<>();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < calculation.length; i++) {
            if (calculation[i] >= 'A' && calculation[i] <= 'Z') {
                sb.append(calculation[i] + "");
            } else {
                if (calculation[i] == '(') op.push(calculation[i]);
                else if (calculation[i] == ')') {
                    while (!op.isEmpty() && op.peek() != '(') {
                        sb.append(op.pop());
                    }
                    if (!op.isEmpty()) {
                        op.pop();
                    }
                } else { //연산자인 경우
                    while (!op.isEmpty() && precedence(op.peek()) >= precedence(calculation[i])) {
                        sb.append(op.pop());
                    }
                    op.push(calculation[i]);
                }
            }
        }

        while (!op.isEmpty()) {
            sb.append(op.pop());
        }
        System.out.println(sb);
    }

    public static int precedence(char op) {
        if (op == '*' || op == '/') return 2;
        else if (op == '+' || op == '-') return 1;
        else return 0;
    }
}
