class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, bool(*)(int, int)> q(
            [] (int a, int b){
                return a<b;
            }
        );
        
        int prev = 1e9;
        for(int i = 0; i<heights.size(); ++i){
            int h = heights[i];
            if(prev < h){
                int need = h - prev;
                q.push(need);
                while(ladders && bricks < need && q.size()){
                    bricks += q.top(); q.pop();
                    ladders--;
                }
                if(bricks < need) return i -1;
                bricks -= need;
            }
            prev = h;
        }

        return heights.size() -1;
    }
};