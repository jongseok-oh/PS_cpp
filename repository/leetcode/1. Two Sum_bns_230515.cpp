class Solution {
public:
    struct Pair{
        int num, idx;
    };
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Pair> vec(nums.size());

        for(int i = 0, len = nums.size(); i<len; i++){
            vec[i] = {nums[i], i};
        }

        sort(vec.begin(), vec.end(), [](Pair a, Pair b){
            return a.num < b.num;
        });

        for(int i = 0, len = vec.size(); i<len; i++){
            int tTarget = target - vec[i].num;

            int left = i, right = len;

            while(left + 1 < right){
                int mid = (left + right)>>1;
                
                if(vec[mid].num == tTarget){
                    return {vec[i].idx, vec[mid].idx};
                }

                if(vec[mid].num > tTarget)
                    right = mid;
                else left = mid;
            }
        }
        return {};
    }
};