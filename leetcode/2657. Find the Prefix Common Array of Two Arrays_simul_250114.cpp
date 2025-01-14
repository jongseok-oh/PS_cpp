class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ret(n);
        vector<bool> aVisit(n+1), bVisit(n+1);

        for(int i = 0; i<n; ++i){
            aVisit[A[i]] = true;
            bVisit[B[i]] = true;
            for(int j = 0; j<=n; ++j){
                ret[i] += aVisit[j] & bVisit[j];
            }
        }
        
        return ret;
    }
};