class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> stack;
        int ret = 0, n = height.size();

        for(int r = 0; r<n; ++r){
            while(stack.size() && height[stack.back()] < height[r]){
                int d = stack.back(); stack.pop_back();
                if(stack.empty()) break;
                int l = stack.back();
                
                int h = min(height[l], height[r]) - height[d];
                int w = r - l - 1;
                ret += h * w;
            }
            stack.push_back(r);
        }
        return ret;
    }
};