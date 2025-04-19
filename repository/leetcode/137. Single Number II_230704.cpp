class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int& num: nums) m[num]++;

        for(auto it = m.begin(); it != m.end(); it++)
            if(it->second == 1) return it->first;
        
        return -1;
    }
};