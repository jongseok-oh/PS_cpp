#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> con[20001];
bool visit[20001];

int solution(int n, vector<vector<int>> edge) {
    for(auto& ed: edge){
        con[ed[0]].push_back(ed[1]);
        con[ed[1]].push_back(ed[0]);
    }
    
    visit[1] = true;
    
    queue<int> q;
    q.push(1);
    
    int ret = -1;
    while(q.size()){
        int qsize = q.size();
        ret = qsize;
        while(qsize--){
            int t = q.front(); q.pop();
            
            for(int nNode: con[t]){
                if(visit[nNode]) continue;
                visit[nNode] = true;
                q.push(nNode);
            }
        }
    }
    return ret;
}