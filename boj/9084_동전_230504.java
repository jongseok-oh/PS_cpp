import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        while(T-->0){
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            int coins[] = new int[n];

            for(int i = 0; i<n; i++) coins[i] = Integer.parseInt(st.nextToken());

            int m = Integer.parseInt(br.readLine());

            int dp[] = new int[m+1];

            dp[0] = 1;

            for(int i = 0; i<n; i++){

                int coin =  coins[i];

                for(int j = coin; j <= m; j++){
                    dp[j] += dp[j-coin];
                }
            }

            sb.append(dp[m]).append("\n");
        }
        System.out.print(sb);
    }
}
