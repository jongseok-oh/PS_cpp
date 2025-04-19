import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		
		int arr[] = new int[n];
		for(int i =0; i<n; i++) arr[i] = Integer.parseInt(st.nextToken());
		
		Arrays.sort(arr);
		
		long ans = 0;
		for(int i = 0; i<n-2; i++) {
			int tar = -arr[i];
			
			int low = i+1, high = n - 1;
			while(low < high) {
				int sum = arr[low] + arr[high];
				if(sum > tar) high--; 
				else if(sum < tar)low++;
				else {
					if(arr[low] == arr[high]) {
						int t = high - low + 1;
						ans += t * (t-1)/2;
						break;
					}
					int tlow = low, thigh = high;
					while(arr[tlow] == arr[low]) low++;
					while(arr[thigh] == arr[high]) high--;
					ans += (low - tlow) * (thigh - high);
				}
			}
		}
		System.out.println(ans);
	}
}