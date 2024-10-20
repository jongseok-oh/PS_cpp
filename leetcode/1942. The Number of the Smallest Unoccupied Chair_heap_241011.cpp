class Solution {
    using pii = pair<int, int>;
    struct Friend{
        int idx, arr, leave;   
    };
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<Friend> friends(n);
        for(int i = 0; i<n; ++i){
            auto& f = friends[i];
            f.idx = i;
            f.arr = times[i][0];
            f.leave = times[i][1];
        }

        sort(friends.begin(), friends.end(), [&](auto& f1, auto& f2){
            return f1.arr < f2.arr;
        });

        priority_queue<int, vector<int>, greater<int>> emptyChairs;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        int newChair = 0;
        for(const auto& [idx, arr, leave] : friends){
            while(q.size() && q.top().first <= arr){
                emptyChairs.push(q.top().second);
                q.pop();
            }

            int myChair = -1;
            if(emptyChairs.size()){
                myChair = emptyChairs.top();
                emptyChairs.pop();
            }else myChair = newChair++;
            
            if(idx == targetFriend) return myChair;
            q.push({leave, myChair});
        }

        return -1;
    }
};