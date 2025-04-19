class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> stack;
        for(int i = 0; i<n; ++i){
            int p = prices[i];
            while(stack.size() && prices[stack.back()] >= p){
                int idx = stack.back();
                stack.pop_back();
                prices[idx] -= p;
            }
            stack.push_back(i);
        }

        return prices;
    }
};