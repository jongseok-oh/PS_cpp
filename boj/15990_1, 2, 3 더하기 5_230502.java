import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        int MOD =  (int)1e9 + 9;

        int dp[][] = new int [100001][4];

        dp[1][1] = 1;
        dp[2][2] = 1;
        dp[3][3] = 1;

        for(int i = 3; i<100001; i++){
            for(int num = 1; num<=3;num++){
                for(int tar = 1; tar<=3; tar++) {
                    if (num == tar) continue;
                    dp[i][num] += dp[i-num][tar];
                    dp[i][num] %= MOD;
                }
            }
        }

        while(T-->0){
            int n = Integer.parseInt(br.readLine());

            int ans = 0;

            for(int num = 1; num<=3; num++)
                ans = (ans + dp[n][num]) % MOD;

            sb.append(ans).append("\n");
        }
        System.out.print(sb);
    }
}
