class Solution {
    bool _remove(int val, unordered_map<int, int>& cnt){
        if(!cnt.count(val)) return false;
        if(--cnt[val] == 0) cnt.erase(val);
        return true;
    }
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;

        unordered_map<int, int> cnt;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int card: hand) {
            ++cnt[card]; q.push(card);
        }

        int groupCnt = hand.size() / groupSize;
        while(true){
            if(!q.size()) return false;

            int _min = q.top(); q.pop();
            if(!_remove(_min, cnt)) continue;
            
            for(int i = _min + 1; i<_min + groupSize; ++i){
                if(!_remove(i, cnt)) return false;
            }

            if(!--groupCnt) break;
        }
        return true;
    }
};