#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[1001];

long long solution(vector<int> weights) {
    int _max = -1e9;
    for(int& w: weights){
        cnt[w]++;
        _max = max(_max, w);
    }
    
    
    long long ans = 0;
    
    for(int i = 100; i<=_max; ++i){
        if(!cnt[i]) continue;
        
        ans += 1LL * cnt[i] * (cnt[i]-1) / 2;
        
        if(i * 2 <= _max)
            ans += 1LL * cnt[i] * cnt[i*2];
        
        if(i % 2 == 0 && i / 2 * 3 <= _max)
            ans += 1LL * cnt[i] * cnt[i/2*3];
        
        if(i % 3 == 0 && i / 3 * 4 <= _max)
            ans += 1LL * cnt[i] * cnt[i/3*4];
    }
    
    return ans;
}