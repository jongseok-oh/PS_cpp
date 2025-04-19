class Solution {
    using pii = pair<int, int>;
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        priority_queue<pii> q;
        for(auto& event : events){
            q.emplace(event[2], event[0]);
        }

        int ret = 0;
        for(auto& event : events){
            int end = event[1], value1 = event[2];
            while(q.size()){
                auto [value2, start] = q.top();
                if(start <= end) q.pop();
                else break;
            }
            int value2 = q.empty()?0:q.top().first;
            ret = max(ret, value1 + value2);
        }
        return ret;
    }
};