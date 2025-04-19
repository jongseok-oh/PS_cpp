class Solution {
    using ll = long long;
public:
    ll maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int num : nums) q.push(num);

        ll ret = 0;
        while(k--){
            int top = q.top(); q.pop();
            ret += top;
            q.push(ceil(1.0 * top/3));
        }

        return ret;
    }
};