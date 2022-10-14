import java.util.*;
import java.io.*;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		long facto[] = new long [1000001];
		
		facto[0] = 1; facto[1] = 1; 
		
		for(int i = 2; i<1000001; i++) {
			facto[i] = facto[i-1] * i % mod; 
		}
		
		for(int t = 1; t<=T; t++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			
			long ans = facto[n] * squared(facto[n - r] * facto[r] % mod, mod -2) % mod;
			bw.write("#"+t+" "+ans + "\n");
		}
		bw.flush();
	}
	
	
	static long mod = 1234567891;

	
	static long squared(long num, long indices) {
		if(indices == 0) return (long)1;
		
		long half =  indices/2;
		
		long ret = squared(num, half);
		ret = ret * ret % mod;
		if((indices & 1) == 1) ret = ret * num %mod;
		return ret;
	}
}
