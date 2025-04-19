class Solution {
    bool canChange(const string& s1, const string& s2){
        if(s1.size() != s2.size()) return false;

        int diffCnt = 0;
        for(int i = 0, n = s1.size(); i<n; ++i){
            if(s1[i] != s2[i]) ++diffCnt;
        }

        return diffCnt == 1;
    }
    
    vector<int> con[5001];

    int bfs(int start, int end, int n){
        queue<int> q;
        vector<bool> visit(n+1);

        visit[start] = true;
        q.push(start);

        int cnt = 0;
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                int t = q.front(); q.pop();
                if(t == end) return cnt + 1;
                for(int next : con[t]){
                    if(visit[next]) continue;
                    visit[next] = true;
                    q.push(next);
                }
            }
            ++cnt;
        }

        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        int endWordIdx = -1;
        for(int i = 0; i<n; ++i){
            if(wordList[i] == endWord){
                endWordIdx = i;
            }
            if(canChange(beginWord, wordList[i])){
                con[n].push_back(i);
                con[i].push_back(n);
            }
        }

        if(endWordIdx == -1) return 0;

        for(int i = 0; i<n-1; ++i){
            for(int j = i + 1; j<n; ++j){
                if(canChange(wordList[i], wordList[j])){
                    con[i].push_back(j);
                    con[j].push_back(i);
                }
            }
        }

        return bfs(n, endWordIdx, n);
    }
};