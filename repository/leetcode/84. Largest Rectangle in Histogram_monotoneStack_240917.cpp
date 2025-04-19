class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stack;
        stack.push(-1);
        
        int ret = -1;
        for(int i = 0; i<n; ++i){
            while(stack.top() != -1 && heights[stack.top()] >= heights[i]){
                int th = heights[stack.top()];
                stack.pop();
                int prevIdx = stack.top();
                ret = max(ret, (i - prevIdx - 1) * th);
            }
            stack.push(i);
        }

        while(stack.top() != -1){
            int th = heights[stack.top()];
            stack.pop();
            int prevIdx = stack.top();
            ret = max(ret, (n - prevIdx - 1) * th);
        }

        return ret;
    }
};