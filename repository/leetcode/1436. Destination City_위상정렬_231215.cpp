class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> outdegree;
        
        for(auto& p: paths) {
            ++outdegree[p[0]];
            if(outdegree.find(p[1]) == outdegree.end())
                outdegree[p[1]] = 0;
        }

        for(auto kv: outdegree){
            if(kv.second == 0) return kv.first;
        }

        return "zz";
    }
};