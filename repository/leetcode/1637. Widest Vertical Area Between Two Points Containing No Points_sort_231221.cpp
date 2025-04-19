class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](auto& a, auto& b){
            return a[0] < b[0];
        });
        
        int ret = 0, n = points.size();
        for(int i = 0; i<n-1; ++i){
            int diff = points[i + 1][0] - points[i][0];
            if(diff > ret) ret = diff;
        }
        return ret;
    }
};