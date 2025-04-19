import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder bw = new StringBuilder();

        int MOD = (int)1e9 + 9;

        int dp[] = new int[1000001];

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for(int i = 4; i<1000001; i++){
            for(int num = 1; num<=3; num++)
                dp[i] = (dp[i] + dp[i-num])%MOD;
        }

        int T = Integer.parseInt(br.readLine());
        while(T-->0){
            int n = Integer.parseInt(br.readLine());
            bw.append(dp[n] + "\n");
        }
        System.out.print(bw);
    }
}
