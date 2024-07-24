class Solution {
    int convert(int num, vector<int>& mapping, int p){
        if(num == 0){
            return p == -1?mapping[0]:0;
        }
        return convert(num/10, mapping, 0)*10 + mapping[num%10];
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        stable_sort(nums.begin(), nums.end(), [&](auto& a, auto& b){
            int ca = convert(a, mapping,-1), cb = convert(b, mapping,-1);
            return ca < cb;    
        });
        return nums;
    }
};