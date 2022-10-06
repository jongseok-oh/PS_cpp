import java.io.*;
import java.util.*;

public class Main {
		public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		while(T-- > 0) {
			int n = Integer.parseInt(br.readLine());

			int[] loc[] = new int[n+2][2];
			
			for(int i = 0; i<=n+1; i++) {
				st = new StringTokenizer(br.readLine());
				int y = Integer.parseInt(st.nextToken());
				int x = Integer.parseInt(st.nextToken());
				loc[i] = new int[] {y,x}; 
			}
			
			List<Integer> edge[] = new List[n+2];
			
			for(int i =0; i<n+2; i++) edge[i] = new ArrayList<>();
			
			for(int i = 0; i<n+2; i++) for(int j = 0; j<n+2; j++) {
				if(i == j) continue;
				
				int dist = Math.abs(loc[i][0] - loc[j][0])
						+ Math.abs(loc[i][1] - loc[j][1]);

				if(dist <= 1000) {
					edge[i].add(j);
					edge[j].add(i);
				}
			}
			
			Queue<Integer> q = new ArrayDeque<>();
			
			boolean visit[] = new boolean [n+2];
			
			q.offer(0); visit[0] = true;
			
			while(!q.isEmpty()) {
				int node = q.poll();
				
				if(node == n+1) {
					bw.write("happy\n");
					break;
				}
				for(int nnode: edge[node]) {
					if(visit[nnode]) continue;
					visit[nnode] = true;
					q.offer(nnode);
				}
			}
			if(!visit[n+1]) bw.write("sad\n");
		}
		bw.flush();
	}
}
