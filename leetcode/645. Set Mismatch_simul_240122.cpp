class Solution {
    int cnt[10001];
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        for(int& num : nums) ++cnt[num];
        
        vector<int> ret(2);
        for(int i = 1; i<=n; ++i){
            if(!cnt[i]) ret[1] = i;
            else if(cnt[i] == 2) ret[0] = i;
        }

        return ret;
    }
};