class Solution {
    int n;
    unordered_map<string, int> mapper;
    vector<int> skillBit;

    bool visit[1<<16];
    struct Info{
        int tvisit;
        vector<int> vec;
    };
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();

        for(int i = 0; i<n; i++)
            mapper[req_skills[i]] = i;
        
        for(auto& p: people){
            int bit = 0;
            for(auto& s: p) bit |= (1<<mapper[s]);
            skillBit.push_back(bit);
        }

        queue<Info> q;

        q.push({0, vector<int>()});

        while(q.size()){
            Info tt = q.front(); q.pop();
            if(tt.tvisit == (1<<n) - 1) return tt.vec;

            for(int i = 0; i<skillBit.size(); i++){
                int nvisit = tt.tvisit | skillBit[i];

                if(!visit[nvisit]){
                    visit[nvisit] = true;

                    auto temp = tt.vec;
                    temp.push_back(i);

                    q.push({nvisit, temp});
                }
            }
        }

        return skillBit;
    }
};