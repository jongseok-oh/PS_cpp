class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n);

        for(int i = 0; i<n; ++i){
            int tTemp = temperatures[i];

            while(st.size() && st.top().second < tTemp){
                auto&[idx, temp] = st.top(); st.pop();
                ans[idx] = i - idx;
            }
            st.push({i, tTemp});
        }

        return ans;
    }
};