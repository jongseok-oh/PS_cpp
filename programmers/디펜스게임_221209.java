import java.util.*;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        int answer = 0;
        
        Queue<Integer> q = new PriorityQueue<>((a,b)->b-a);
        
        for(int e: enemy){
            q.offer(e);
            if(n - e >= 0){
                n -= e;
                answer++;
            }else{
                while(n < e && k>0 && !q.isEmpty()){
                    k--;
                    n += q.poll();
                }
                if(n - e >=0){
                    n -= e; answer++;
                }else break;
            }
        }
        return answer;
    }
}