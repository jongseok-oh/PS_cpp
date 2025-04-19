class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxQ;
        deque<int> minQ;

        int n = nums.size(), ret = 0;
        for(int i = 0, j = 0; i<n; ++i){
            while(maxQ.size() && nums[i] > maxQ.back())
                maxQ.pop_back();
            maxQ.push_back(nums[i]);
            while(minQ.size() && nums[i] < minQ.back())
                minQ.pop_back();
            minQ.push_back(nums[i]);

            if(maxQ.front() - minQ.front() <= limit){
                ret = max(ret, i - j + 1);
            }else{
                if(maxQ.front() == nums[j]) maxQ.pop_front();
                if(minQ.front() == nums[j]) minQ.pop_front();
                ++j;
            }
        }
        return ret;
    }
};