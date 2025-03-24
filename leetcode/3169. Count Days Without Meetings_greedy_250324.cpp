class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        int prev = 0, ret = 0;
        for(auto& meeting : meetings){
            int s = meeting[0], e = meeting[1];
            if(prev + 1 < s){
                ret += s - prev - 1;
            }
            prev = max(prev, e);
        }
        if(days > prev) ret += days - prev;
        return ret;
    }
};