class Solution {
    public:
        string findCommonResponse(vector<vector<string>>& responses) {
            unordered_map<string, int> cnt;
            for(auto& response : responses){
                unordered_set<string> set(response.begin(), response.end());
                
                for(const string& s : set) ++cnt[s];
            }
            
            string ret = ""; int maxCnt = -1;
            
            for(auto& [k, v] : cnt){
                if(v > maxCnt){
                    maxCnt = v;
                    ret = k;
                }else if(v == maxCnt && ret > k){
                    ret = k;
                }
            }
            
            return ret;
        }
    };