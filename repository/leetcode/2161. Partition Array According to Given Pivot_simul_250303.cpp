class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int pivotCnt = 0;
        vector<int> left, right;
        for(int num : nums){
            if(num < pivot){
                left.push_back(num);
            }else if(num > pivot){
                right.push_back(num);
            }else ++pivotCnt;
        }
        vector<int> ret;
        ret.insert(ret.end(), left.begin(), left.end());
        while(pivotCnt--) ret.push_back(pivot);
        ret.insert(ret.end(), right.begin(), right.end());

        return ret;
    }
};