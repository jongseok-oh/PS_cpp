import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int k = Integer.parseInt(br.readLine());

        int a = 1, b = 0;

        while(k-->0){
            int ta = a, tb = b;
            ta = b;
            tb += a;
            a = ta; b = tb;
        }
        System.out.print(a + " " + b);
    }
}
