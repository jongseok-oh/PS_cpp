class Solution {
    int ingrid[2000];
    vector<int> con[2000];
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        for(auto& p: prerequisites){
            int a = p[0], b = p[1];

            con[b].push_back(a);
            ingrid[a]++;
        }

        int cnt = 0;
        queue<int> q;

        for(int i = 0; i<n; i++) if(!ingrid[i]) q.push(i);

        while(q.size()){
            int t = q.front(); q.pop();
            cnt++;

            for(int& next: con[t])
                if(--ingrid[next] == 0) q.push(next);
        }

        return cnt == n;
    }
};