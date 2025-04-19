import java.io.*;
import java.util.*;

public class Solution {

    static class Node{
        int left, right;
        char data;

        public Node(int left, int right, char data){
            this.left = left; this.right = right; this.data = data;
        }
    }

    static void inorder(BufferedWriter bw, Node[] nodes, int t) throws IOException {
        if(nodes[t].left != -1){
            inorder(bw, nodes, nodes[t].left);
        }
        bw.write(nodes[t].data);
        if(nodes[t].right != -1){
            inorder(bw, nodes, nodes[t].right);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        for(int tt =1; tt<=10; tt++){
            int n = Integer.parseInt(br.readLine());

            Node [] nodes = new Node[n+1];

            for(int j = 0; j<n; j++){
                st = new StringTokenizer(br.readLine());

                int myNum = Integer.parseInt(st.nextToken());
                char data = st.nextToken().charAt(0);

                int left = -1, right = -1;

                if(st.hasMoreTokens()) left = Integer.parseInt(st.nextToken());
                if(st.hasMoreTokens()) right = Integer.parseInt(st.nextToken());

                nodes[myNum] = new Node(left, right, data);
            }
            bw.write("#" + tt + " ");
            inorder(bw, nodes, 1);
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}
