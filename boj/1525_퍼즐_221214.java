import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int map[] = new int[9];
		
		int k = 0;
		for(int i =0; i<3; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j =0; j<3; j++) map[k++] = Integer.parseInt(st.nextToken());
		}
		boolean visit[] = new boolean[370000];
		
		factorial[1] = 1;
		for(int i =2; i<9; i++) factorial[i] = factorial[i -1] * i; 
		
		int dest = calOrder(new int[] {1,2,3,4,5,6,7,8,0});
		int t = calOrder(map);
		visit[t] = true;
		Queue<Integer> q = new ArrayDeque<>();
		q.offer(t);
		int ans = 0;
		
		int swapArr[][] = {{1,3},{0,2,4},{1,5},{0,4,6},{1,3,5,7},{2,4,8},{3,7},{4,6,8},{5,7}};
		
		while(!q.isEmpty()) {
			int qsize = q.size();
			while(qsize-->0) {
				int tt = q.poll();
				if(tt == dest) {
					System.out.print(ans); return;
				}
				int[] tmap = makeMap(tt);
				
				int hole = -1;
				for(int i =0; i<tmap.length; i++)
					if(tmap[i] == 0) {
						hole = i; break;
					}
				for(int m : swapArr[hole]) {
					int cmap[] = Arrays.copyOf(tmap, tmap.length);
					swap(cmap, m, hole);
					
					int norder = calOrder(cmap);
					if(visit[norder] == false) {
						visit[norder] = true;
						q.offer(norder);
					}
				}
			}
			ans++;
		}
		System.out.print(-1);
	}
	
	static int factorial[] = new int[9];
	
	static int calOrder(int[] map) {
		int order  = 0;
		LinkedList<Integer> ll = new LinkedList<>();
		for(int i = 0; i<9; i++) ll.add(i);
		for(int i = 0; i<9; i++)
		{
			int numOrder = 0;
			while(ll.get(numOrder) != map[i]) numOrder++;
			ll.remove(numOrder);
			order += numOrder * factorial[8-i];
		}
		return order;
	}
	
	static int[] makeMap(int order) {
		int map[] = new int[9];
		LinkedList<Integer> ll = new LinkedList<>();
		for(int i = 0; i<9; i++) ll.add(i);
		
		for(int i = 0; i<8; i++) {
			int nOrder = order / factorial[8-i]; 
			map[i] = ll.get(nOrder);
			order %= factorial[8-i];
			ll.remove(nOrder);
		}
		map[8] = ll.get(0);
		return map;
	}
	
	static void swap(int [] map, int i1, int i2) {
		int temp = map[i1];
		map[i1] = map[i2];
		map[i2] = temp;
	}
}
