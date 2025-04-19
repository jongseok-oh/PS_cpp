class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int num1 = 0, num2 = 0;

        for(int& num: nums){
            if(!cnt1 && num2 != num){
                cnt1 = 1; num1 = num;
            }else if(!cnt2 && num1 != num){
                cnt2 = 1; num2 = num;
            }else if(num1 == num) cnt1++;
            else if(num2 == num) cnt2++;
            else cnt1--, cnt2--;
        }

        cnt1 = 0; cnt2 = 0;
        for(int& num: nums){
            if(num == num1) cnt1++;
            else if(num == num2) cnt2++;
        }

        vector<int> ret;
        int n = nums.size();

        if(cnt1 > n/3) ret.push_back(num1);
        if(cnt2 > n/3) ret.push_back(num2);

        return ret;
    }
};