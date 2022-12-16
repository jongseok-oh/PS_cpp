import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		boolean sosu[] = new boolean[n+1];
		
		for(int i =2, end = (int)Math.sqrt(n); i<=end; i++) {
			if(!sosu[i]) {
				for(int j = i + i; j<=n; j += i) {
					sosu[j] = true;
				}
			}
		}
		List<Integer> sosus = new ArrayList<>();
		
		for(int i = 2; i<=n; i++) if(!sosu[i]) sosus.add(i);
		
		int ans = 0;
		int low = 0, high = 0;
		int tSum = 0;
		
		while(true) {
			if(tSum >= n) {
				tSum -= sosus.get(low++);
			}else {
				if(high >= sosus.size()) break;
				tSum += sosus.get(high++);
			}
			if(tSum == n) ans++;
		}
		System.out.println(ans);
	}
}