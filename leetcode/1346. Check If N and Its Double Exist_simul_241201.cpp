class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> cnt;

        for(int num : arr) ++cnt[num];
        for(int num : arr){
            if(num == 0){
                if(cnt[0] >= 2) return true;
            }else if(cnt.count(num*2)) return true;
        }

        return false;
    }
};