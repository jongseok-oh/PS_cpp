class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> numString(n);

        for(int i = 0; i<n; ++i){
            numString[i] = to_string(nums[i]);
        }

        sort(numString.begin(), numString.end(), [&](const string& a, const string& b){
            return a + b > b + a;
        });

        if(numString[0] == "0") return "0";

        string ret = "";
        for(const string& num : numString) ret += num;

        return ret;
    }
};