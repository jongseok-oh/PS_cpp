import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int dp[] = new int[n+1];

        for(int i = 1; i<=n; i++) dp[i] = 5;

        for(int i = 1; i*i<=n; i++) dp[i*i] = 1;

        for(int i = 2; i<=n; i++){

            for(int j = 1; j*j<i; j++)
                dp[i] = Math.min(dp[i], 1 + dp[i-j*j]);
        }
        System.out.println(dp[n]);
    }
}
