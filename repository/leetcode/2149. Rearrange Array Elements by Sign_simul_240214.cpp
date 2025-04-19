class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        queue<int> pos, neg;
        for(int num: nums){
            if(num > 0) pos.push(num);
            else neg.push(num);
        }

        vector<int> ret(n);
        
        for(int i = 0; i<n; ++i){
            if(i&1) {ret[i] = neg.front(); neg.pop();}
            else {ret[i] = pos.front(); pos.pop();}
        }

        return ret;
    }
};