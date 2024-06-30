class Solution {
    int ap[100001], bp[100001];
    int getP(int v, int* p){
        if(!p[v]) return v;
        return p[v] = getP(p[v], p);
    }
    bool _merge(int a, int b, int * p){
        int ap = getP(a, p), bp = getP(b, p);
        if(ap == bp) return false;
        
        if(ap < bp) p[bp] = ap;
        else p[ap] = bp;
        
        return true;
    }
    bool aliceMerge(int a, int b){
        return _merge(a, b, ap);
    }
    bool bobMerge(int a, int b){
        return _merge(a, b, bp);
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [&](auto& a, auto& b){
            return a[0] > b[0];
        });
        int aCnt = 0, bCnt = 0, edgeCnt = 0;
        for(auto& edge : edges){
            int type = edge[0], a = edge[1], b = edge[2];
            if(type == 1){
                if(aliceMerge(a, b)) {
                    aCnt++; edgeCnt++;
                }
            }else if(type == 2){
                if(bobMerge(a,b)) {
                    bCnt++;  edgeCnt++;
                }
            }else{
                bool au = aliceMerge(a, b);
                bool bu = bobMerge(a,b);
                if(au) aCnt++;
                if(bu) bCnt++;
                if(au || bu) edgeCnt++;
            }
        }
        return (aCnt == n-1 && bCnt == n-1)?edges.size() - edgeCnt:-1;
    }
};