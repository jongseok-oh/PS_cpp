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
		
		int idxArr[] = {-1,-1,-1};
		long minDiff = Long.MAX_VALUE;
		for(int i =0; i<n; i++) for(int j =i; j<n; j++) {
			if(i == j) continue;
			int idx = search(i,j,arr);
			long diff = Math.abs((long)arr[i] + arr[j] + arr[idx]);
			if(minDiff > diff) {
				minDiff = diff;
				idxArr[0] = i; idxArr[1] = j; idxArr[2] = idx;
			}
		}
		Arrays.sort(idxArr);
		bw.write(arr[idxArr[0]] + " " + arr[idxArr[1]] + " " + arr[idxArr[2]]);
		bw.flush();
	}
	
	static int search(int i, int j, int[] arr) {
		int low = -1, high = arr.length;
		
		long tar = -(arr[i] + arr[j]);
		
		while(low +1 < high) {
			int mid = (low + high) >>1;
			if(arr[mid]>=tar) high = mid;
			else low = mid;
		}
		int right, left, t = high;
		while((t == i || t == j) && t < arr.length) t++;
		right = left = t;
		right++; left--;
		
		while((right == i || right == j) && right < arr.length) right++;
		while((left == i || left == j || left == arr.length) && left >= 0) left--;
		
		long rightValue = (right >= arr.length?5000000000L:arr[right]);
		long leftValue = (left == -1?5000000000L:arr[left]);
		long tValue = (t >= arr.length?5000000000L:arr[t]);
		
		
		Long arrl[][] = {{rightValue, (long)right},{leftValue, (long)left}, {tValue, (long)t}};
		Arrays.sort(arrl, (l1, l2) -> {return
				Long.compare(
				Math.abs(l1[0] -(long)tar), Math.abs(l2[0] -(long)tar));});
		long ans = arrl[0][1]; 
		return (int)ans;
	}
}