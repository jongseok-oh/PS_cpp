import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		while(T-->0) {
			int n = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			
			int visit[] = new int[n+1];
			Arrays.fill(visit, -1);
			
			for(int i =1; i<=n; i++)
				student[i] = Integer.parseInt(st.nextToken());
			
			ans = 0;
			for(int i =1; i<=n; i++) {
				if(visit[i] == -1) solve(i,visit,0,new ArrayList<>());
			}
			bw.write(ans+"\n");
		}
		bw.flush();
	}
	static int student[] = new int[100001];
	static int ans;
	static void solve(int t, int visit[], int cnt, List<Integer> past) {
		visit[t] = cnt;
		past.add(t);
		int ncnt = visit[student[t]]; 
		if(ncnt != -1) {
			if(past.size() <= ncnt)
				ans += cnt + 1;
			else{
				if(past.get(ncnt) != student[t])  
					ans += cnt + 1;
				else ans += ncnt;
			}
			return;
		}
		
		solve(student[t], visit, cnt+1, past);
	}
}
