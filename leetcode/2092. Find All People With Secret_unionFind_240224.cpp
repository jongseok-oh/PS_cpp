class Solution {
    int p[100000];

    int getP(int t){
        if(t == p[t]) return t;
        return p[t] = getP(p[t]);
    }

    void merge(int a, int b){
        int aP = getP(a), bP = getP(b);
        if(aP < bP) p[bP] = aP;
        else p[aP] = bP;
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [&](auto& a, auto& b){
            return a[2] < b[2];
        });

        for(int i = 0; i<n; ++i) p[i] = i;
        p[firstPerson] = 0;

        int m = meetings.size();
        for(int i = 0, j = 1; i<m; i = j){
            int time = meetings[i][2];
            merge(meetings[i][0], meetings[i][1]);
            while(j<m && meetings[j][2] == time) {
                merge(meetings[j][0], meetings[j][1]);
                j++;
            }

            for(int k = i; k<j; ++k){
                int a = meetings[k][0], b = meetings[k][1];
                if(getP(a) != 0) p[a] = a;
                if(getP(b) != 0) p[b] = b;
            }
        }

        vector<int> ret;

        for(int i = 0; i<n; ++i)
            if(getP(i) == 0) ret.push_back(i);

        return ret;
    }
};