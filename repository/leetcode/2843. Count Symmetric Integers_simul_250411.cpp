class Solution {
    bool check(int num){
        string num_ = to_string(num);
        int n = num_.size();
        if(n&1) return false;

        int left = 0, right = 0;
        for(int i = 0; i<n/2; ++i){
            left += num_[i] - '0';
            right += num_[i+n/2] - '0';
        }
        return left == right;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        for(int i = low; i<=high; ++i){
            if(check(i)) ++ret;
        }
        return ret;
    }
};