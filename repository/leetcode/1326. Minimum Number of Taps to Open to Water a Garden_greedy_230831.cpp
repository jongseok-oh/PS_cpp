class Solution {
    int covers[10001];
public:
    int minTaps(int n, vector<int>& ranges) {
        for(int i = 0; i<ranges.size(); i++){
            
            int start = max(i - ranges[i], 0);
            int tCover = i + ranges[i];
            int end = min(n, tCover);

            for(int idx = start; idx <= end; idx++){
                if(covers[idx] < tCover - idx)
                    covers[idx] = tCover - idx;
            }
        }

        int ans = 0, idx = 0;

        while(idx < n){
            if(!covers[idx]) return -1;
            ++ans;
            idx += covers[idx];
        }

        return ans;
    }
};