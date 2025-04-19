class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indeg;
        unordered_map<string, vector<string>> con;

        int n = recipes.size();
        for(int i = 0; i<n; ++i){
            string recipe = recipes[i];
            indeg[recipe] = ingredients[i].size();
            for(string& ingredient : ingredients[i]){
                con[ingredient].push_back(recipe);
            }
        }

        unordered_set<string> canMake;
        queue<string> q;
        for(string& sup : supplies) q.push(sup);

        while(q.size()){
            string t = q.front(); q.pop();
            canMake.insert(t);

            for(string& next : con[t]){
                if(--indeg[next] == 0){
                    q.push(next);
                }
            }
        }

        vector<string> ret;
        for(string& recipe : recipes){
            if(canMake.count(recipe)){
                ret.push_back(recipe);
            }
        }

        return ret;
    }
};