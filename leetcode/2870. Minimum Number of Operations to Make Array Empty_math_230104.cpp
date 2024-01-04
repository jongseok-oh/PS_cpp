class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for(int& num: nums) ++cnts[num];
        
        int ret = 0;
        for(auto& kv: cnts){
            int cnt = kv.second;
            int q = cnt/3, r = cnt%3;

            if(r != 1) ret += q + r/2;
            else{
                if(!q) return -1;
                else ret += (q - 1) + (r+3)/2;
            }
        }

        return ret;
    }
};