import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Queue<Integer> q = new ArrayDeque<>();

        int ans = 0;

        boolean visit[] = new boolean[n+1];

        q.add(0);
        visit[0] = true;

        while(!q.isEmpty()){
            int qsize = q.size();

            while(qsize-->0){
                int t = q.poll();

                int tp2 = t + 2, tp5 = t + 5;

                if(tp2 == n || tp5 == n){
                    System.out.print(ans+1);
                    return;
                }

                if(tp2 <= n && !visit[tp2]){
                    q.add(tp2);
                    visit[tp2] = true;
                }
                if(tp5 <= n && !visit[tp5]){
                    q.add(tp5);
                    visit[tp5] = true;
                }
            }
            ans++;
        }

        System.out.print(-1);
    }
}
