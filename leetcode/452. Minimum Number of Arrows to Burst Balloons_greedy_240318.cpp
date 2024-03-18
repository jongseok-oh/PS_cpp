class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](auto& a, auto& b){
            return a[1]< b[1] || (a[1] == b[1] && a[0] < b[0]);
        });

        int ret = 1, n = points.size();
        int tar = points[0][1];
        for(int i = 1; i<n; ++i){
            if(points[i][0] > tar){
                ++ret;
                tar = points[i][1];
            }
        }
        return ret;
    }
};