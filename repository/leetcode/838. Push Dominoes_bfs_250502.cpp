class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        queue<int> q;
        for(int i = 0; i<n; ++i){
            char c = dominoes[i];
            if(c != '.') q.push(i);
        }

        while(q.size()){
            int qsize = q.size();

            unordered_map<int, char> candi;
            while(qsize--){
                int idx = q.front(); q.pop();
                int dir = dominoes[idx] == 'L'?-1:1;
                int nIdx = idx + dir;

                if(nIdx < 0 || nIdx == n || dominoes[nIdx] != '.'){
                    continue;
                }

                if(candi.count(nIdx)){
                    candi[nIdx] = '.';
                }else candi[nIdx] = dominoes[idx];
            }

            for(auto& [idx, c] : candi){
                if(c != '.') {
                    dominoes[idx] = c;
                    q.push(idx);
                }
            }
        }

        return dominoes;
    }
};