import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        int cards[] = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++)
            cards[i] = Integer.parseInt(st.nextToken());

        int dp[] = new int[n+1];

        Arrays.fill(dp, (int)1e9);
        dp[0] = 0;

        for(int i = 1; i<=n; i++){
            for(int j = 0; j<i; j++){
                dp[i] = Math.min(dp[i], dp[i-j-1] + cards[j]);
            }
        }
        System.out.print(dp[n]);
    }
}
