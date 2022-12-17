import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
public class Main {
	
	static int[] posr,posc,tarr,tarc; 
	static int k;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		posr = new int[k];
		posc = new int[k];
		tarr = new int[k];
		tarc = new int[k];
		
		int num = -1, r = -1, c = -1;
		for(int i =0; i<k; i++) {
			st = new StringTokenizer(br.readLine());
			num = Integer.parseInt(st.nextToken());
			r = Integer.parseInt(st.nextToken()) - 1;
			c = Integer.parseInt(st.nextToken()) - 1;
			tarr[i] = r;
			tarc[i] = c;
			posr[i] = (num - 1)/n;
			posc[i] = (num - 1)%n;
		}
		
		for(int i =0; i<k; i++) {
			int tarrr = tarr[i], tarcc = tarc[i];
			int posrr = posr[i], poscc = posc[i];
			
			int rmove = (tarrr - posrr + n)%n;
			int cmove = (tarcc - poscc + n)%n;
			bw.write(rmove+cmove+"\n");
			rrotate(posrr,cmove,n);
			crotate((poscc + cmove)%n,rmove,n);
		}
		bw.flush();
	}
	static void rrotate(int posrr, int cmove, int n) {
		for(int i =0; i<k; i++) {
			if(posr[i] == posrr) posc[i] = (posc[i] + cmove)%n;
		}
	}
	static void crotate(int poscc, int rmove, int n) {
		for(int i =0; i<k; i++) {
			if(posc[i] == poscc) posr[i] = (posr[i] + rmove)%n;
		}
	}
}