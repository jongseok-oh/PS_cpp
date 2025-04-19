class Solution {

bool isDetonate(vector<int>& bomb1, vector<int>& bomb2){
    double x = bomb1[0] - bomb2[0];
    double y = bomb1[1] - bomb2[1];
    return sqrt(x*x + y*y) <= bomb1[2];
}

int getDetonateCnt(int t, vector<vector<int>>& bombs, vector<bool>& visit){
    visit[t] = true;

    int ret = 1;

    for(int i = 0; i<bombs.size(); i++){
        if(!visit[i] && isDetonate(bombs[t], bombs[i]))
            ret += getDetonateCnt(i, bombs, visit);
    }
    return ret;
}

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        int ans = 1;

        for(int i = 0; i<n; i++){
            vector<bool> visit(n);
            ans = max(ans, getDetonateCnt(i, bombs,visit));
        }

        return ans;
    }
};