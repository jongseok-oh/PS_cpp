import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int vol[] = new int[n];

        st = new StringTokenizer(br.readLine());

        for(int i = 0; i<n; i++) vol[i] = Integer.parseInt(st.nextToken());

        boolean dp[][] = new boolean[n+1][m+1];

        dp[0][s] = true;

        for(int i = 1; i<=n; i++){
            for(int j = 0; j <=m; j++){
                if(dp[i-1][j]) {
                    if (j + vol[i - 1] <= m)
                        dp[i][j + vol[i - 1]] = true;
                    if (j - vol[i - 1] >= 0)
                        dp[i][j - vol[i - 1]] = true;
                }
            }
        }

        int ans = -1;

        for(int i = m; i>=0; i--){
            if(dp[n][i]){
                ans = i; break;
            }
        }

        System.out.print(ans);
    }
}
