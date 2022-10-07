import java.util.*;
import java.io.*;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t<=T; t++) {
			int n = Integer.parseInt(br.readLine());
			int m = Integer.parseInt(br.readLine());
			
			int cmp[][] = new int [n + 1][n + 1];
			
			while(m-- > 0) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				
				cmp[a][b] = -1;
				cmp[b][a] = 1;
			}
			
			for(int mid = 1; mid <= n; mid++) {
				for(int i = 1; i<=n; i++) {
					if(i == mid) continue;
					for(int j = 1; j<= n; j++) {
						if(i == j || j == mid) continue;
						
						if(cmp[i][mid] == 1 && cmp[mid][j] == 1)
							cmp[i][j] = 1;
						else if(cmp[i][mid] == -1 && cmp[mid][j] == -1)
							cmp[i][j] = -1;
					}
				}
			}
			
			int cnt = n;
			
			for(int i = 1; i<=n; i++) {
				for(int j =1; j<=n; j++) {
					if(i == j) continue;
					if(cmp[i][j] == 0) {
						cnt--; break;
					}
				}
			}
			bw.write("#"+t+" " +cnt+"\n");
		}
		bw.flush();
	}
}
