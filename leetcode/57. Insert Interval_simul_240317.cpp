class Solution {
    bool isOverlap(vector<int>& origin, vector<int>& other){
        return !(origin[1] < other[0] || origin[0] > other[1]);
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;

        bool isIn = false;
        if(!intervals.size() || newInterval[0] < intervals[0][0]) {
            ret.push_back(newInterval);
            isIn = true;
        }
        for(auto& interval : intervals){
            int s = interval[0], e = interval[1];
            if(isOverlap(newInterval, interval)){
                if(!isIn){
                    int ts = min(newInterval[0], interval[0]);
                    int te = max(newInterval[1], interval[1]);
                    ret.push_back({ts, te});
                    isIn = true;
                }else{
                    vector<int>& ni = ret.back();
                    ni[0] = min(ni[0], interval[0]);
                    ni[1] = max(ni[1], interval[1]);
                }
            }else {
                if(
                    (!ret.size() || ret.back()[1] < newInterval[0])
                    && newInterval[1] < interval[0]
                ){
                    ret.push_back(newInterval);
                    isIn = true;
                }
                ret.push_back(interval);
            }
        }

        if(!isIn) ret.push_back(newInterval);

        return ret;
    }
};