class Solution {
    using ll = long long;
public:
    ll maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        auto cmp = [&nums] (int a, int b){
            return nums[a] < nums[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> right(cmp);
        for(int i = 1; i<n; ++i) right.push(i);

        ll ret = 0;
        int left = nums[0];
        for(int i = 1; i<n-1; ++i){
            int num = nums[i];
            while(right.top() <= i) right.pop();
            ret = max(ret, ((ll)left - num) * nums[right.top()]);
            left = max(left, num);
        }

        return ret;
    }
};