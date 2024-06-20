class Solution {
    bool check(vector<int>& position, int m, int diff){
        int prev = position[0]; --m;
        for(int i = 1, n = position.size(); i<n; ++i){
            if(position[i] - prev >= diff){
                prev = position[i];
                --m;
            }
        }
        return m <= 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1, high = 1e9;
        while(low + 1< high){
            int mid = (low + high) >>1;
            if(check(position, m, mid)) low = mid;
            else high = mid;
        }

        return low;
    }
};