class Solution {
    typedef long long ll;
    typedef pair<int, ll> pii;
    int cnt[100];
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [&](auto& a, auto& b){
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> unusedRoom;

        auto cmp = [](pii& a, pii& b){
            return a.second > b.second || (a.second == b.second && a.first > b.first);
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> usedRoom;

        for(int i = 0; i<n; ++i) unusedRoom.push(i);

        for(auto& m: meetings){
            int num; ll endTime;
            while(usedRoom.size() && usedRoom.top().second <= m[0]){
                unusedRoom.push(usedRoom.top().first);
                usedRoom.pop();
            }
            if(unusedRoom.size()){
                num = unusedRoom.top();
                unusedRoom.pop();
                endTime = m[1];
            }else{
                auto [tNum, tEndTime] = usedRoom.top(); usedRoom.pop();
                num = tNum;
                endTime = tEndTime + (m[1] - m[0]);
            }
            cnt[num]++;
            usedRoom.push({num, endTime});
        }

        int maxCnt = -1, ret = -1;
        for(int i = 0; i<n; ++i){
            if(cnt[i] > maxCnt){
                maxCnt = cnt[i];
                ret = i;
            }
        }
        return ret;
    }
};