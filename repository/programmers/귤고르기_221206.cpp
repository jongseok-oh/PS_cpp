#include <algorithm>

using namespace std;

int sizeCnt[10000001];

bool cmp(int a, int b){
    return a>b;
}

int solution(int k, vector<int> tangerine) {
    int max_size = -1;
    for(int t: tangerine){
        max_size = max(max_size, t);
        sizeCnt[t]++;
    }
    sort(sizeCnt+1, sizeCnt + max_size + 1, cmp);
    
    int ans = 0, tcnt = 0;
    for(int i = 1; i<=max_size; i++){
        ans++;
        tcnt += sizeCnt[i];
        if(tcnt >= k) break;
    }
    return ans;
}