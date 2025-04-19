#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;

int dist[201][201];
int s[20000], e[20000], v[20000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;

    // overflow 방지
    memset(dist, 0x3f, sizeof dist);
    for(int i = 1; i<=n; ++i) dist[i][i] =0;
    

    for(int i = 0; i<m; ++i){
        cin>>s[i]>>e[i]>>v[i];
        dist[s[i]][e[i]] = min(dist[s[i]][e[i]], v[i]);
        dist[e[i]][s[i]] = min(dist[e[i]][s[i]], v[i]);
    }

    for(int mid = 1; mid<=n; ++mid) for(int f = 1; f<=n; ++f) for(int t = 1; t<=n; ++t)
        dist[f][t] = min(dist[f][t], dist[f][mid] + dist[mid][t]);
        
    int ret = 0x7fffffff;
    for(int i = 1; i<=n; ++i){
        int _max = -1;
        for(int j = 0; j<m; j++)
            _max = max(_max, dist[i][s[j]] + dist[i][e[j]] + v[j]);
        ret = min(_max, ret);
    }
    cout<<ret/2<<'.'<<(ret&1?5:0);
}