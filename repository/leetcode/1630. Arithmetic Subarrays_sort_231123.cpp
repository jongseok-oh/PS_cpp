class Solution {
    bool chk(vector<int> vec){
        sort(vec.begin(), vec.end());
        
        int diff = vec[1] - vec[0];

        for(int i = 2; i<vec.size(); ++i)
            if(vec[i] - vec[i-1] != diff) return false;

        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ret;

        int m = l.size();
        for(int i = 0; i<m; ++i)
            ret.push_back(
                chk(vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1))
            );

        return ret;
    }
};