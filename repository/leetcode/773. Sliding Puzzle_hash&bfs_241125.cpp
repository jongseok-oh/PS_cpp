class Solution {
    int pows[7];
    vector<int> dir[6] = {
        {1,3},
        {0,2,4},
        {1,5},
        {0,4},
        {1,3,5},
        {2,4}
    };

    int _hash(vector<vector<int>>& board){
        int hash = 0;
        for(int i = 0; i<2; ++i) for(int j = 0; j<3; ++j){
            hash = hash * 31 + board[i][j];
        }
        return hash;
    }

    int getEmptyLocation(int hash){
        for(int i = 0; i<6; ++i){
            if(hash % 31 == 0) return i;
            hash /= 31;
        }
        return -1;
    }

    int getNum(int hash, int idx){
        return hash % pows[idx + 1] / pows[idx];
    }

    int _swap(int hash, int idx1, int idx2){
        int num1 = getNum(hash, idx1);
        int num2 = getNum(hash, idx2);
        return hash - num1 * pows[idx1] + num1 * pows[idx2] - num2 * pows[idx2] + num2 * pows[idx1];
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> solve = {{1,2,3}, {4,5,0}};
        int sHash = _hash(solve);

        pows[0] = 1;
        for(int i = 1; i<7; ++i){
            pows[i] = pows[i-1] * 31;
        }
        
        unordered_set<int> visit;
        queue<int> q;
        int bHash = _hash(board);
        visit.insert(bHash);
        q.push(bHash);

        int ret = 0;
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                int tHash = q.front(); q.pop();
                if(tHash == sHash) return ret;
                
                int idx = getEmptyLocation(tHash);
                for(int nIdx : dir[idx]){
                    int nHash = _swap(tHash, idx, nIdx);
                    if(!visit.count(nHash)){
                        visit.insert(nHash);
                        q.push(nHash);
                    }
                }
            }
            ++ret;
        }

        return -1;
    }
};