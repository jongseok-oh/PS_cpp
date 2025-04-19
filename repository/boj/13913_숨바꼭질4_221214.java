import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		int p[] = new int[150001];
		
		Arrays.fill(p, -1);
		
		int time = 0;
		Queue<Integer> q = new ArrayDeque<>();
		boolean find = false;
		q.offer(n);
		while(!q.isEmpty()) {
			int qsize= q.size();
			while(qsize-->0) {
				int t = q.poll();
				if(t == k) {
					bw.write(time + "\n");
					find =true; break;
				}
				for(int next : new int[] {t-1,t+1,t*2}) {
					if(next>= 0 && next <= 150000 && p[next] ==-1) {
						p[next] = t;
						q.offer(next);
					}
				}
			}
			if(find) break;
			time++;
		}
		trace(k, n, p, bw);
		bw.flush();
	}
	
	static void trace(int t, int n,int[] p,BufferedWriter bw) throws IOException {
		if(t == n) {
			bw.write(n + " ");
			return;
		}
		trace(p[t], n, p, bw);
		bw.write(t + " ");
	}
}
