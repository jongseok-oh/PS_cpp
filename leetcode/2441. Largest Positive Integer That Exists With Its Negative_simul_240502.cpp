class Solution {
    bool negative[1001], positive[1001];
public:
    int findMaxK(vector<int>& nums) {
        for(int num: nums){
            if(num < 0) negative[-num] = true;
            else positive[num] = true;
        }

        for(int i = 1000; i>0; --i)
            if(negative[i] && positive[i]) return i;
        
        return -1;
    }
};