class Solution {
    int numberOfDigits(int num){
        int cnt = 0;
        while(num){
            ++cnt;
            num /= 10;
        }
        return cnt;
    }
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for(int num : nums){
            ret += (numberOfDigits(num) % 2 == 0);
        }
        
        return ret;
    }
};