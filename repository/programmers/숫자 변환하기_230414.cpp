#include <vector>

using namespace std;

bool visit[1000001];
int q[1000001];
int qfront, qcnt;

int solution(int x, int y, int n) {
    qfront = 0; qcnt = 0;
    
    q[qcnt++] = x;
    visit[x] = true;
    
    int ans = 0;
    while(qfront != qcnt){
        
        int tqcnt = qcnt - qfront;
        
        while(tqcnt--){
            int t = q[qfront++];
        
            if(t == y) return ans;
            
            for(int next : {t+n, t*2, t*3}){
                if(next < 1000001 && !visit[next]){
                    visit[next] = true;
                    q[qcnt++] = next;
                }
            }
        }
        ans++;
    }
    
    return -1;
}