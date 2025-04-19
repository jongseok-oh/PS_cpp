import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		
		int home[] = new int[n];
		
		for(int i =0; i<n; i++) home[i] = Integer.parseInt(br.readLine());
		Arrays.sort(home);
		int low = 1, high = home[n-1] - home[0] + 1;
		
		while(low +1 < high) {
			int mid = (low + high)>>1;
			if(chk(c,mid,home)) high = mid;
			else low = mid;
		}
		System.out.print(low);
	}
	
	static boolean chk(int c, int mid, int[] home) {
		int tc = 1, idx = 0;
		while(true) {
			int tloc = home[idx];
			while(idx<home.length && home[idx] - tloc < mid) idx++;
			if(idx == home.length) break;
			tc++;
		}
		return tc < c;
	}
}
