class Solution {
    
public:
    bool primeSubOperation(vector<int>& nums) {
        bitset<1002> visit;
        for(int i = 2, n = sqrt(1001); i<=n; ++i){
            if(!visit[i]){
                for(int j = i + i; j<=1001; j += i){
                    visit[j] = true;
                }
            }
        }
        vector<int> primes;
        for(int i = 2; i<=1001; ++i){
            if(!visit[i]) primes.push_back(i);
        }

        for(int n = nums.size(), i = n-2; i>=0; --i){
            if(nums[i + 1] > nums[i]) continue;
            int diff = nums[i] - nums[i + 1];
            auto it = upper_bound(primes.begin(), primes.end(), diff);
            if(it == primes.end() || *it >= nums[i]) return false;
            nums[i] -= *it;
        }

        return true;
    }
};