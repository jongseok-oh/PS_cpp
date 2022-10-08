import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int n,m;
		
		st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		int map [][] = new int[n][m];
		
		for(int i =0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j =0; j<m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		List<List<int[]>> islands = new ArrayList<>();
	
		int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};
		
		boolean visit[][] = new boolean[n][m];
		
		for(int i =0; i<n; i++) for(int j =0; j<m; j++) {
			if(map[i][j] == 1 && !visit[i][j]) {
				Queue<int[]> q = new ArrayDeque<>();
				
				int [] loc = new int[]{i,j};
				
				q.offer(loc);
				
				List<int[]> island = new ArrayList<>();
				island.add(loc);
				
				while(!q.isEmpty()) {
					int [] tloc = q.poll();
					
					int ty = tloc[0],
						tx = tloc[1];
					
					for(int dir = 0; dir<4; dir++) {
						int ny = ty + dy[dir],
							nx = tx + dx[dir];
						
						if(ny <0 || ny>= n || nx<0 || nx>= m) continue;
						if(visit[ny][nx]) continue;
						if(map[ny][nx] == 0) continue;
						
						visit[ny][nx] = true;
						
						int [] nloc = new int[] {ny,nx};
						q.offer(nloc);
						island.add(nloc);
					}
				}
				islands.add(island);
			}
		}
		
		int cnt = islands.size();
		
		List<int[]> road = new ArrayList<>();
		boolean conn[][] = new boolean [cnt][cnt];
		
		for(int i =0; i<cnt; i++) for(int j =0; j<cnt; j++) {
			if(i == j) continue;
			if(conn[j][i]) continue;
			
			List<int[]> land1 = islands.get(i);
			List<int[]> land2 = islands.get(j);
			
			int minLen = 99;
			
			for(int a = 0; a<land1.size(); a++) for(int b = 0; b<land2.size(); b++) {
				int loc1[] = land1.get(a);
				int loc2[] = land2.get(b);
				
				if(loc1[0] == loc2[0]) {
					int x1 = loc1[1],
						x2 = loc2[1];
					
					int y = loc1[0];
					
					int tarLen = Math.abs(x1- x2) - 1;
					int tx = Math.min(x1, x2);
					int sx = tx;
					
					while(map[y][++tx] != 1);
					if(tarLen == tx - sx - 1)
						if(tarLen >= 2 && minLen > tarLen) minLen = tarLen;
				}else if(loc1[1] == loc2[1]) {
					int y1 = loc1[0],
						y2 = loc2[0];
					
					int x = loc1[1];
					
					int tarLen = Math.abs(y1- y2) - 1;
					int ty = Math.min(y1, y2);
					int sy = ty;
					
					while(map[++ty][x] != 1);
					if(tarLen == ty - sy - 1)
						if(tarLen >= 2 && minLen > tarLen) minLen = tarLen;
				}
			}
			
			if(minLen != 99) {
				road.add(new int[] {i,j,minLen});
				conn[i][j] = true;
			}
		}
		
		Collections.sort(road, (r1, r2) -> r1[2] - r2[2]);
		
		parent = new int[cnt];
		for(int i =0; i<cnt; i++) parent[i] = i;
		
		int tCnt = 0;
		int sum = 0;
		
		for(int [] troad : road) {
			if(Union(troad[0], troad[1])) {
				sum += troad[2];
				tCnt++;
			}
			if(tCnt == cnt - 1) {System.out.println(sum); return;}
		}
		System.out.println(-1);
	}
	
	static int parent[];
	
	static int getP(int t) {
		if(parent[t] == t) return t;
		return parent[t] = getP(parent[t]);
	}
	
	static boolean Union(int a, int b) {
		int pa = getP(a);
		int pb = getP(b);
		
		if(pa == pb) return false;
		
		parent[pb] = pa;
		
		return true;
	}
}
