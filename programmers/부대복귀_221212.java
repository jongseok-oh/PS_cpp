import java.util.*;
class Solution {
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int dist[] = new int[n+1];
        Arrays.fill(dist, -1);
        dist[destination] = 0;
        
        List<Integer> edges[] = new List[n+1];
        
        for(int i = 1; i<=n; i++) edges[i] = new ArrayList<>();
        
        for(int [] road: roads){
            edges[road[0]].add(road[1]);
            edges[road[1]].add(road[0]);
        }
        
        Queue<Integer> q = new ArrayDeque<>();
        
        q.offer(destination);
        
        int depth = 1;
        while(!q.isEmpty()){
            int qsize = q.size();
            while(qsize-->0){
                int t = q.poll();
                for(int nnode : edges[t]){
                    if(dist[nnode] != -1) continue;
                    dist[nnode] = depth;
                    q.offer(nnode);
                }
            }
            depth++;
        }
        int ans[] = new int[sources.length];
        for(int i =0, len = sources.length; i<len; i++) ans[i] = dist[sources[i]];
        return ans;
    }
}