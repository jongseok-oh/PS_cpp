class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ret = "";

        for(int i = 0; i<n; ++i){
            ret += nums[i][i] == '0'?'1':'0';
        }

        return ret;
    }
};