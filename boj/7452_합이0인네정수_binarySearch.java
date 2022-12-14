import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		
		int arr[][] = new int[n][4];
		
		for(int i =0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j =0; j<4; j++) arr[i][j] = Integer.parseInt(st.nextToken());
		}
		
		int arrA[] = new int[n * n];
		int arrB[] = new int[n * n];
		
		int idx = 0;
		for(int i =0; i<n; i++) for(int j =0; j<n; j++) {
			arrA[idx] = arr[i][0] + arr[j][1];
			arrB[idx++] = arr[i][2] + arr[j][3];
		}
		
		// arrA를 정렬하면 cache hit rate가 증가해서 속도가 빨라짐 ㄷㄷ;
        Arrays.sort(arrA);
		Arrays.sort(arrB);
		
		long ans = 0;
		for(int i =0; i<n*n; i++) {
			ans += upper(-arrA[i], arrB) - lower(-arrA[i], arrB);
		}
		System.out.println(ans);
	}
	
	static int lower(int tar, int[]arrB) {
		int low = -1, high = arrB.length;
		while(low +1 < high) {
			int mid = (low + high) >>1;
			if(arrB[mid] >= tar) high = mid;
			else low = mid;
		}
		return high;
	}
	
	static int upper(int tar, int[]arrB) {
		int low = -1, high = arrB.length;
		while(low +1 < high) {
			int mid = (low + high) >>1;
			if(arrB[mid] > tar) high = mid;
			else low = mid;
		}
		return high;
	}
}