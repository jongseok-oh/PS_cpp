class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ret = 0;

        for(int i = 1; i<points.size(); ++i){
            auto& p1 = points[i-1];
            auto& p2 = points[i];

            ret += max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]));
        }

        return ret;
    }
};