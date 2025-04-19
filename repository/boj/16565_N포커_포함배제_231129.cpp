#include <iostream>

using namespace std;

const int MOD = 1e4 + 7;

int n;
int nCk[53][53];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;

    for(int i = 0; i<53; ++i) nCk[i][0] = 1;
    for(int i = 1; i<53; ++i) for(int j = 1; j<53; ++j)
        nCk[i][j] = (nCk[i-1][j-1] + nCk[i-1][j]) % MOD;
    int ret = 0;
    for(int i = 1; n - 4 * i >= 0; ++i){
        ret = (ret + (i&1?1:-1) * nCk[13][i] * nCk[52 - 4 * i][n - 4 * i]) % MOD;
    }
    
    cout<<(ret>=0?ret:ret + MOD);

    return 0;
}