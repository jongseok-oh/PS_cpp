import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int dy[] = {-1,1,0,0}, dx[] = {0,0,1,-1};
		
		int R, C, M;
		st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		fish fishes[][] = new fish[R][C];
		
		while(M-- > 0) {
			int r,c,s,d,z;
			st = new StringTokenizer(br.readLine());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			z = Integer.parseInt(st.nextToken());
			r--; c--; d--;
			
			fishes[r][c] = new fish(s,d,z);
		}
		
		int fisherC = -1;
		
		int sharkSum = 0;
		
		int magicR = (R - 1) * 2;
		int magicC = (C - 1) * 2;
		
		while(++fisherC < C) {
			
			for(int i = 0; i<R; i++) {
				if(fishes[i][fisherC] != null) {
					sharkSum += fishes[i][fisherC].z;
					fishes[i][fisherC] = null;
					break;
				}
			}
			
			fish tempFishes[][] = new fish[R][C];
			
			for(int i =0; i<R; i++) for(int j =0; j<C; j++) {
				if(fishes[i][j] != null) {
					fish t = fishes[i][j];
					int s = t.s, d = t.d, z = t.z;
					int tr = i, tc = j;
					
					if(d == 0 || d == 1) {
						tr = d == 1? i: magicR - i; 
						
						tr = (tr + s)%magicR;
						
						if(tr >= magicR/2) {
							d = 0;
							tr = magicR - tr;
						}else d = 1;
						
					}else {
						tc = d == 2? j : magicC - j;
						
						tc = (tc + s)%magicC;
						
						if(tc >= magicC/2) {
							d = 3;
							tc = magicC - tc;
						}else d = 2;
					}
					
					if(tempFishes[tr][tc] == null || tempFishes[tr][tc].z < z)
						tempFishes[tr][tc] = new fish(s,d,z);
				}
			}
			
			fishes = tempFishes;
		}
		System.out.print(sharkSum);
	}
	
	static class fish{
		int s,d,z;
		
		public fish(int s, int d, int z) {
			this.s = s;
			this.d = d;
			this.z = z;
		}
	}
}
