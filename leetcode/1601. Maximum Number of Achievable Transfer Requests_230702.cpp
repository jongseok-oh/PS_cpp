class Solution {
    int n,m;

    int calc(int visit, vector<vector<int>>& requests){
        vector<int> building(n);

        int cnt = 0;
        for(int i = 0; i<m; i++){
            if(visit & (1<<i)){
                cnt++;
                building[requests[i][0]]--;
                building[requests[i][1]]++;
            }
        }

        bool chk = true;
        for(int i = 0; i<n; i++)
            if(building[i]){
                chk = false; break;
            }
        
        if(chk) return cnt;
        else return -1;
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        this->n = n; this->m = requests.size();

        int ans = 0;
        for(int i = 1; i<(1<<m); i++){
            ans = max(ans, calc(i, requests));
        }

        return ans;
    }
};