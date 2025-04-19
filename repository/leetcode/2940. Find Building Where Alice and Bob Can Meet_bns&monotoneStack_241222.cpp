class Solution {
    struct Query{
        int f, t, idx;  
    };
    int upper_bound(int height, vector<int>& stack, vector<int>& h){
        int low = -1, high = stack.size();
        while(low + 1 < high){
            int mid = (low + high)>>1;
            if(h[stack[mid]] <= height) high = mid;
            else low = mid;
        }
        return low == -1?-1:stack[low];
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& queries) {
        int n = h.size(), m = queries.size();
        vector<int> ret(m);
        vector<Query> qs(m);
        for(int i = 0; i<m; ++i){
            auto& [f, t, idx] = qs[i];
            f = queries[i][0];
            t = queries[i][1];
            if(f > t) swap(f, t);
            idx = i;
        }

        sort(qs.begin(), qs.end(), [](auto& a, auto& b){
            return a.t > b.t;
        });

        int last = n;
        vector<int> stack;
        for(int i = 0; i<m; ++i){
            const auto& [a, b, idx] = qs[i];
            if(a == b || h[b] > h[a]) {
                ret[idx] = b;
                continue;
            }
            
            for(int j = last - 1; j>=b; --j){
                int t = h[j];
                while(stack.size() && h[stack.back()] < t){
                    stack.pop_back();
                }
                stack.push_back(j);
            }
            last = b;

            int height = max(h[a], h[b]);
            ret[idx] = upper_bound(height, stack, h);
        }

        return ret;
    }
};