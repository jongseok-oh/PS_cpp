class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> cnt(501);
        for(int num : nums) ++cnt[num];
        for(int i = 1; i<=500; ++i){
            if(cnt[i]&1) return false;
        }
        return true;
    }
};