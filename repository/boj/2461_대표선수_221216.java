import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		Integer student[][] = new Integer[n][m];
		
		for(int i =0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j =0; j<m; j++) student[i][j] = Integer.parseInt(st.nextToken());
			Arrays.sort(student[i], (i1,i2) -> i2-i1);
		}
		
		int _min = 0x7fffffff;
		
		Queue<int[]> q = new PriorityQueue<>((i1,i2) -> i2[0] - i1[0]);
		
		for(int i =0; i<n; i++){
			int t = student[i][0];
			_min = Math.min(_min, t);
			q.offer(new int[] {t,i,0});
		}
		
		int ans = 0x7fffffff;
		
		while(q.size() > 0) {
			int[] t = q.poll();
			ans = Math.min(t[0] - _min, ans);
			
			if(t[2] == m-1) break;
			
			_min = Math.min(_min, student[t[1]][t[2] + 1]);
			
			q.offer(new int[] {student[t[1]][t[2] + 1] ,t[1], t[2] + 1});
		}
		System.out.println(ans);
	}
}