#include <iostream>

using namespace std;

const int MOD = 1e4 + 7;

int n;
string str;

// str.substr(i, j)의 부분 문자열 중
// 팰린드롬의 개수
int dp[1020][1020];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>str;
    n = str.size();
    for(int i = 0; i<n; ++i) dp[i][1] = 1;
    for(int i = 0; i<n-1; ++i){
        dp[i][2] = 2;
        if(str[i] == str[i +1]) ++dp[i][2];
    }

    for(int len = 3; len<=n; ++len){
        for(int i = 0; i<=n-len; ++i){
            dp[i][len] = MOD + dp[i][len - 1]
                + dp[i + 1][len - 1]
                - (str[i] == str[i + len -1]?-1:dp[i + 1][len - 2]);
            dp[i][len] %= MOD;
        }
    }

    cout<<dp[0][n];
}