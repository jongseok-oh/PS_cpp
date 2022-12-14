import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		Queue<Integer> q = new ArrayDeque<>();
		boolean visit[][] = new boolean[500001][2];
		visit[n][0] = true;
		q.offer(n);
		int ans = 0;
		
		while(!q.isEmpty()) {
			int qsize = q.size();
			while(qsize-->0){
				int t = q.poll();
				if(visit[k][ans%2]) {
					System.out.print(ans); return;
				}
				for(int next: new int[] {t-1,t+1, t*2}) {
					if(next >= 0 && next <= 500000 && !visit[next][(ans+1)%2]) {
						visit[next][(ans+1)%2] = true;
						q.offer(next);
					}
				}
			}
			ans++;
			k += ans;
			if(k > 500000) break;
		}
		System.out.print(-1);
	}
}
