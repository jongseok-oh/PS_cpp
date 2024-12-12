class Solution {
    using ll = long long;
public:
    ll pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        for(int gift : gifts){
            q.push(gift);
        }

        while(k-- && q.size()){
            int t = q.top(); q.pop();
            int remain = floor(sqrt(t));
            q.push(remain);
        }

        ll ret = 0;
        while(q.size()){
            ret += q.top(); q.pop();
        }

        return ret;
    }
};