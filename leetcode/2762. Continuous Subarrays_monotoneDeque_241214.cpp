class Solution {
    using ll = long long;
public:
    ll continuousSubarrays(vector<int>& nums) {
        ll ret = 0;
        int n = nums.size(), left = 0;
        deque<int> minQ, maxQ;
        for(int i = 0; i<n; ++i){
            int num = nums[i];
            while(minQ.size() && nums[minQ.back()] < num){
                minQ.pop_back();
            }
            minQ.push_back(i);
            while(maxQ.size() && nums[maxQ.back()] > num){
                maxQ.pop_back();
            }
            maxQ.push_back(i);

            while(minQ.size() && nums[minQ.front()] - num > 2){
                left = max(left, minQ.front() + 1);
                minQ.pop_front();
            }
            while(maxQ.size() && num - nums[maxQ.front()] > 2){
                left = max(left, maxQ.front() + 1);
                maxQ.pop_front();
            }
            
            ret += i - left + 1;
        }
        return ret;
    }
};