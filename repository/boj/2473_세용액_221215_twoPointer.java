import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		
		int arr[] = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i =0; i<n; i++) arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);
		
		long minDiff = Long.MAX_VALUE;
		int ans[] = {-1,-1,-1};
		for(int i =0; i<arr.length - 2; i++) {
			int s[] = search(i,arr);
			long tDiff =Math.abs((long)arr[i] + arr[s[0]] + arr[s[1]]);
			if(minDiff > tDiff){
				minDiff = tDiff;
				ans[0] = i;
				ans[1] = s[0];
				ans[2] = s[1];
			}
			if(minDiff == 0) break;
		}
		bw.write(arr[ans[0]] + " " + arr[ans[1]] + " " + arr[ans[2]]);
		bw.flush();
	}
	
	static int[] search(int idx, int[] arr) {
		int low = idx + 1, high = arr.length - 1;
		int ans[] = {low, high};
		long sum = Long.MAX_VALUE;
		while(low <high) {
			long tSum = (long)arr[idx] + arr[low] + arr[high];
			
			if(Math.abs(sum) > Math.abs(tSum)) {
				sum =  tSum;
				ans[0] = low;
				ans[1] = high;
			}
			if(tSum >0) high--;
			else low++;
		}
		return ans;
	}
}