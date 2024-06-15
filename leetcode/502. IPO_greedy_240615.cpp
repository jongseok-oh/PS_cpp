class Solution {
    struct CP{int c,p;};
    
    void insert(int& end, int w, priority_queue<int>& q,const vector<CP>& cps){
        for(int n = cps.size(); end<n; ++end){
            auto [c, p] = cps[end];
            if(c > w) break;
            q.push(p);
        }
    }
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<CP> cps(n);
        
        for(int i = 0; i<n; ++i){
            CP& cp = cps[i];
            cp.c = capital[i];
            cp.p = profits[i];
        }
        sort(cps.begin(), cps.end(), [&](const CP& a, const CP& b){
            return a.c < b.c;
        });

        int end = 0, ret = w;
        priority_queue<int> q;
        insert(end, w, q, cps);

        while(k-- && q.size()){
            int p = q.top(); q.pop();
            ret += p; w += p;
            insert(end, w, q, cps);
        }
        
        return ret;
    }
};