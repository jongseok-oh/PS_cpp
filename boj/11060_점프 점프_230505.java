import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        int jumpArr[] = new int[n];

        for(int i = 0; i<n; i++) jumpArr[i] = Integer.parseInt(st.nextToken());

        int dp[] = new int[n];

        Arrays.fill(dp, (int)1e9);

        dp[0] = 0;

        for(int loc = 0; loc<n; loc++){
            int jump = jumpArr[loc];

            for(int j = 1; j<=jump; j++)
                if(loc + j <n) dp[loc+j] = Math.min(dp[loc+j], dp[loc] + 1);
        }

        System.out.print((dp[n-1]==(int)1e9?-1:dp[n-1]));
    }
}
