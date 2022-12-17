import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		List<Integer> l = new LinkedList<>();
		
		for(int i = 1; i<=n; i++) l.add(i);
		
		int t = 1, idx = 0;
		while(l.size() != 1) {
			// 5000의 3승은 21억을 넘는다
			long end = (long)Math.pow(t, 3);
			int ridx = (int)(((long)idx + end - 1) % l.size());
			l.remove(ridx);
			idx = ridx % l.size();
			t++;
		}
		System.out.println(l.get(0));
	}
}