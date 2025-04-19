import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		int map[][] = new int [n][m];
		
		safeCnt = 0;
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j =0; j<m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 0) safeCnt++;
			}
		}
		buildWall(0,map,0,0);
		System.out.println(maxSafe);
	}
	
	static int maxSafe = -1;
	static int safeCnt, n, m;
	static int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};
	
	static void buildWall(int cnt, int map[][], int y, int x){
		if(cnt == 3) {
			boolean visit[][] = new boolean [n][m];
			
			int tsafeCnt = safeCnt;
			for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) {
				if(map[i][j] == 2 && !visit[i][j]) {
					Queue<int[]> q = new ArrayDeque<>();
					
					q.offer(new int[] {i,j});
					visit[i][j] = true;
					
					while(!q.isEmpty()) {
						int [] t = q.poll();
						int ty = t[0],
							tx = t[1];
						
						for(int dir = 0; dir<4; dir++) {
							int ny = ty + dy[dir],
								nx = tx + dx[dir];
							
							if(ny <0 || ny>= n || nx<0 || nx>= m) continue;
							if(map[ny][nx] == 1 || map[ny][nx] == 2) continue;
							if(visit[ny][nx]) continue;
							
							tsafeCnt--;
							visit[ny][nx] = true;
							q.offer(new int[] {ny,nx});
							
						}
					}
				}
			}
			maxSafe = maxSafe < tsafeCnt? tsafeCnt: maxSafe;
			return;
		}
		
		int j = x;
		for(int i = y; i<n; i++) {
			for(; j<m; j++) {
				if(map[i][j] == 0) {
					safeCnt--;
					map[i][j] = 1;
					buildWall(cnt+1, map, i, j+1);
					safeCnt++;
					map[i][j] = 0;
				}
			}
			j = 0;
		}
	}
}
