class Solution {
    using ll = long long;
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<>> q;
        for(int num : nums) q.push(num);

        int oper = 0;
        while(true){
            ll first = q.top();
            if(first >= k) break;
            q.pop();
            ll second = q.top();
            q.pop();

            q.push(min(first, second)*2 + max(first, second));

            ++oper;
        }

        return oper;
    }
};