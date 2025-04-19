#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int block[50];
// dp[i][j] = i번째 블록을 놓을 때,
// 두 탑의 차이가 j일 때
// 두 탑 중 큰 탑의 크기
int dp[50][500001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> block[i];

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    dp[0][block[0]] = block[0];

    for(int i = 1; i<n; ++i)
        for (int j = 0; j < 500000; ++j) 
            if (dp[i - 1][j] != -1) {
                // 큰 탑에 놓기
                dp[i][j + block[i]] = max(dp[i][j + block[i]], dp[i - 1][j] + block[i]);
                // 작은 탑에 놓기
                int diff = j - block[i];
                int bigger = max(dp[i - 1][j] - j + block[i], dp[i - 1][j]);
                dp[i][abs(diff)] = max(dp[i][abs(diff)], bigger);
                // 둘 다 안 놓기
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
    cout << (dp[n - 1][0]? dp[n - 1][0]:-1);
}