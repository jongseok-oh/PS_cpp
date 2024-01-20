static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
    typedef long long ll;
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        ll ret = 0;
        vector<int> stack;
        for(int i = 0; i<n; ++i){
            while(stack.size() && arr[stack.back()] > arr[i]){
                int idx = stack.back();
                int left = stack.size()==1?idx:idx-stack[stack.size()-2] - 1;
                int right = i - idx - 1;
                ret = (ret + (ll)arr[idx] * (left + 1) * (right + 1)) % MOD;

                stack.pop_back();
            }
            stack.push_back(i);
        }

        for(int i = stack.size() - 1; i>=0; --i){
            int idx = stack[i];
            int left = i==0?idx:idx-stack[i-1] - 1;
            int right = n - idx - 1;
            ret = (ret + (ll)arr[idx] * (left + 1) * (right + 1)) % MOD;
        }

        return ret;
    }
};