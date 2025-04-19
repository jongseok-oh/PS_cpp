class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // decrease monotonic stack
        stack<int> stack;

        int kNum = INT_MIN;
        for(auto it = nums.rbegin(); it != nums.rend(); ++it){
            if(kNum > *it) return true;

            while(stack.size() && stack.top() < *it){
                kNum = stack.top(); stack.pop();
            }
            stack.push(*it);
        }

        return false;
    }
};