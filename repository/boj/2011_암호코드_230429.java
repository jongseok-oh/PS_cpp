import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String pw = br.readLine();

        if(pw.charAt(0) == '0'){
            System.out.print(0); return;
        }

        int dp[] = new int[pw.length()+1];

        dp[0] = 1; dp[1] = 1;

        int MOD = (int) 1e6;

        for(int i = 1, len = pw.length(); i<len; i++){
            int tnum = pw.charAt(i) - '0';
            int pnum = pw.charAt(i-1) - '0';

            if(tnum == 0){
                if(pnum != 1 && pnum != 2){
                    System.out.print(0); return;
                }

                dp[i+1] += dp[i-1];
            }else{
                if(tnum < 7){
                    if(pnum == 1 || pnum == 2)
                        dp[i+1] += dp[i-1];
                }else{
                    if(pnum == 1)
                        dp[i+1] += dp[i-1];
                }
                dp[i+1] += dp[i];
            }
            dp[i+1] %=MOD;
        }
        System.out.print(dp[pw.length()]);
    }
}
