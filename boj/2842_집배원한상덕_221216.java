import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;
public class Main {
	
	static int n;
	static char map[][];
	static int godo[][];
	static int k;
	static int p[] = {-1,-1};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine());
		map = new char[n][];
		
		k = 0;
		for(int i =0; i<n; i++){
			map[i] = br.readLine().toCharArray();
			for(int j = 0; j<n; j++)
				if(map[i][j] == 'K') k++;
				else if(map[i][j] == 'P') {
					p[0] = i; p[1] = j;
				}
		}
		
		godo = new int[n][n];
		
		Set<Integer> s = new HashSet<>();
		
		for(int i =0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j =0; j<n; j++)
			{
				godo[i][j] = Integer.parseInt(st.nextToken());
				s.add(godo[i][j]);
			}
		}
		
		Integer godos[] = new Integer[s.size()];
		s.toArray(godos);
		
		Arrays.sort(godos);
		
		int minDiff = 0x7fffffff;
		
		int low = 0, high = 0;
		
		while(low <= high && godos[low] <= godo[p[0]][p[1]]) {
			if(!bfs(godos[low], godos[high])) high++;
			else{
				minDiff = Math.min(minDiff, godos[high] - godos[low]);
				low++;
			}
			if(high >= godos.length) break;
		}
		
		System.out.println(minDiff);
	}
	
	static int []dy = {-1,-1,0,1,1,1,0,-1};
	static int []dx = {0,1,1,1,0,-1,-1,-1};
	
	static boolean bfs(int _min, int _max) {
		if(_max < godo[p[0]][p[1]]) return false;
		boolean visit[][] = new boolean[n][n];
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(p);
		visit[p[0]][p[1]] = true;
		int tk = 0;
		while(!q.isEmpty()) {
			int t[] = q.poll();
			if(map[t[0]][t[1]] == 'K') {
				tk++;
				if(tk == k) break;
			}
			for(int dir =0; dir<8; dir++) {
				int ny = t[0] + dy[dir],
					nx = t[1] + dx[dir];
				
				if(ny <0 || ny >=n || nx <0 || nx >= n) continue;
				if(godo[ny][nx] <_min || godo[ny][nx] > _max || visit[ny][nx]) continue;
				visit[ny][nx] = true;
				q.offer(new int[] {ny,nx});
			}
		}
		return tk == k;
	}
}