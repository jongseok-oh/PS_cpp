class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        const int n = costs.size();

        int leftIdx = candidates - 1;
        priority_queue<int> left;
        for(int i = 0; i<candidates; i++) left.push(-costs[i]);

        int rightIdx = n;
        priority_queue<int> right;
        while(rightIdx - 1 != leftIdx && rightIdx > n - candidates)
            right.push(-costs[--rightIdx]);
        
        long long ans = 0;
        while(k--){
            
            if(!right.size() || (left.size() && left.top() >= right.top())){
                ans += -left.top(); left.pop();
                if(leftIdx + 1 != rightIdx) left.push(-costs[++leftIdx]);
            }
            else {
                ans += -right.top(), right.pop();
                if(rightIdx -1 != leftIdx) right.push(-costs[--rightIdx]);
            }
        }

        return ans;
    }
};