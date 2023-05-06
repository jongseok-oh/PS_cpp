import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int scov: scoville) pq.add(scov);
        
        int ans = 0;
        
        while(!pq.isEmpty()){
            if(pq.peek() >= K) return ans;
            
            if(pq.size() == 1) break;
            
            int min1 = pq.poll();
            int min2 = pq.poll();
            
            pq.add(min1 + min2*2);
            
            ans++;
        }
        
        return -1;
    }
}