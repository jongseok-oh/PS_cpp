class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int cnt = 0, tend = -50001;
        for(auto& t: intervals){
            int start = t[0], end = t[1];

            if(start >= tend){
                cnt++; tend = end;
            }
        }

        return intervals.size() - cnt;
    }
};