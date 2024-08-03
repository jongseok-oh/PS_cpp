class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt(1001);
        for(int num : arr) ++cnt[num];
        for(int num : target) --cnt[num];
        for(int c : cnt){
            if(c != 0) return false;
        }
        return true;
    }
};