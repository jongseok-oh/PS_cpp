#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int k, len;
string N,M;

bool dp[2][19][1 << 10];

bool dfs(bool same, int idx, int used, int usedCnt) {
    if (idx == len) return usedCnt == k;
    bool& check = dp[same][idx][used];
    if (check) return false;

    for (char num = same ? N[idx] : '0'; num <= '9'; ++num) {
        int numBit = 1 << (num - '0');
        
        int tempUsedCnt = usedCnt;
        if (!(used & numBit)) {
            if (++tempUsedCnt > k) continue;
        }
        M[idx] = num;
        if (dfs(same && N[idx] == num, idx + 1, used | numBit, tempUsedCnt)) return true;
    }
    check = true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> k;
    len = N.size();
    
    M.resize(len);
    if (k > len || !dfs(true, 0, 0, 0)) {
        int targetLen = max(k, len + 1);
        M = string(targetLen, '0');
        M[0] = '1';
        for (int tk = 2; tk < k; ++tk)
            M[targetLen + tk - k] = tk + '0';
    }
    cout << M;
}