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
		int lidx = 0, ridx = n-1;
		int left = -1, right = -1;
		int tdiff = 0x7fffffff;
		while(lidx < ridx) {
			int sum = arr[lidx] + arr[ridx];
			
			if(tdiff > Math.abs(sum)) {
				tdiff = Math.abs(sum);
				left= lidx; right = ridx;
				if(tdiff == 0) break;
			}
			
			if(sum >0) ridx--;
			else lidx++;
		}
		bw.write(arr[left] + " " + arr[right]);
		bw.flush();
	}
}
