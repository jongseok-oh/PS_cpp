import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int dy[] = {-1,1,0,0}, dx[] = {0,0,1,-1};
		
		int n,m;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		char map[][] = new char[n][];
		
		int y = -1, x = -1;
		
		boolean visit[][][] = new boolean [n][m][1<<6];
		
		for(int i =0; i<n; i++) {
			map[i] = br.readLine().toCharArray();
			for(int j =0; j<m; j++) {
				if(map[i][j] == '0') {
					map[i][j] = '.';
					y = i; x= j;
				}
			}
		}
		
		Queue<minsik> q = new ArrayDeque<>();
		q.offer(new minsik(y,x,0));
		visit[y][x][0] = true;
		
		int move = 0;
		
		while(!q.isEmpty()) {
			
			int size = q.size();
			
			while(size-- > 0) {
				minsik t = q.poll();
				int ty = t.y, tx = t.x,tkeys = t.keys;
				
				if(map[ty][tx] == '1') {
					System.out.println(move); return;
				}
				
				for(int dir = 0; dir<4; dir++) {
					int ny = ty + dy[dir],
						nx = tx + dx[dir];
					
					if(ny <0 || ny >= n || nx <0 || nx>=m) continue;
					if(map[ny][nx] == '#') continue;
					if(visit[ny][nx][tkeys]) continue;
					int ttkey = tkeys;
					if(map[ny][nx] >= 'a' && map[ny][nx] <= 'f') ttkey |= (1<<(map[ny][nx] - 'a'));
					
					if(map[ny][nx] >= 'A' && map[ny][nx] <= 'F') {
						int num = map[ny][nx] - 'A';
						if((ttkey & (1<<num)) != (1<<num)) continue;
					}
					
					visit[ny][nx][ttkey] = true;
					q.offer(new minsik(ny,nx,ttkey));
				}
			}
			move++;
		}
		
		System.out.println(-1);
	}
	
	static class minsik{
		int keys;
		int y,x;
		public minsik(int y, int x, int keys) {
			this.y = y;
			this.x = x;
			this.keys = keys;
		}
	}
}
