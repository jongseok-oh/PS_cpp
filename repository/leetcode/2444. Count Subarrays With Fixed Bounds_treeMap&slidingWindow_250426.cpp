class Solution {
    using ll = long long;
    vector<vector<int>> tokenize(vector<int>& nums, int minK, int maxK){
        vector<vector<int>> tokens;
        for(int i = 0, n = nums.size(); i<n; ++i){
            if(nums[i] >= minK && nums[i] <= maxK){
                tokens.push_back({nums[i++]});
                auto& token = tokens.back();

                while(i < n && nums[i] >= minK && nums[i] <= maxK){
                    token.push_back(nums[i++]);
                }
            }
        }

        return tokens;
    }
    ll countFixedBounds(vector<int>& token, int minK, int maxK){
        map<int, int> treeMap;
        ll ret = 0;
        for(int i = 0, j = 0, n = token.size(); i<n; ++i){
            while(j < n){
                if(treeMap.size()){
                    int _min = (*treeMap.begin()).first;

                    auto end = treeMap.end(); --end;
                    int _max = (*(end)).first;

                    if(_min == minK && _max == maxK) break;
                }
                
                ++treeMap[token[j++]];
            }

            if(treeMap.size()){
                int _min = (*treeMap.begin()).first;

                auto end = treeMap.end(); --end;
                int _max = (*(end)).first;

                if(_min == minK && _max == maxK){
                    ret += n - j + 1;
                }
            }
            
            if(--treeMap[token[i]] == 0){
                treeMap.erase(token[i]);
            }
        }

        return ret;
    }
public:
    ll countSubarrays(vector<int>& nums, int minK, int maxK) {
        auto tokens = tokenize(nums, minK, maxK);

        ll ret = 0;
        for(auto& token : tokens){
            ret += countFixedBounds(token, minK, maxK);
        }

        return ret;
    }
};