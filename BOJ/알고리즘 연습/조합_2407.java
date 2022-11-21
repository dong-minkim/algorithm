
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n= Integer.parseInt(st.nextToken());
        int m= Integer.parseInt(st.nextToken());

        BigInteger numerator = BigInteger.ONE;
        BigInteger denominator = BigInteger.ONE;
        for(int i=0; i<m; i++){
            numerator = numerator.multiply(new BigInteger(String.valueOf(n-i)));
            denominator = denominator.multiply(new BigInteger(String.valueOf(i+1)));
        }

        BigInteger answer = numerator.divide(denominator);

        System.out.println(answer);
    }
}