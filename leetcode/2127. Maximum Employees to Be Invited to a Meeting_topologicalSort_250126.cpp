class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indeg(n);

        for(int i = 0; i<n; ++i){
            ++indeg[favorite[i]];
        }

        queue<int> q;
        for(int i = 0; i<n; ++i){
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> depth(n, 1);
        while(q.size()){
            int t = q.front(); q.pop();
            
            int next = favorite[t];
            depth[next] = max(depth[next], depth[t] + 1);
            if(--indeg[next] == 0) q.push(next);
        }

        int maxCycle = -1, twoCycleTotal = 0;
        for(int i = 0; i<n; ++i){
            if(indeg[i] == 0) continue;

            int t = i, cycle = 0;
            while(indeg[t]){
                indeg[t] = 0;
                ++cycle;
                t = favorite[t];
            }
            
            if(cycle == 2){
                twoCycleTotal += depth[i] + depth[favorite[i]];
            }else maxCycle = max(maxCycle, cycle);
        }

        return max(maxCycle, twoCycleTotal);
    }
};