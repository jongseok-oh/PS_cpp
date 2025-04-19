#include <string>
#include <vector>
#include <cstring>

using namespace std;

int pirodo[3][3] = {
    {1,1,1},
    {5,1,1},
    {25,5,1}
};

int dp[50][6][6][6];
int solve(int idx, int dia, int iron, int stone, vector<int>& minerals){
    if(idx >= minerals.size() || (!dia && !iron && !stone)) return 0;
    int& ret = dp[idx][dia][iron][stone];
    
    if(ret != -1) return ret;
    
    ret = 1e9;
    
    if(dia){
        int sum = 0;
        for(int i = idx, j = 0; i+j<minerals.size()&&j<5; ++j)
            sum += pirodo[0][minerals[i+j]];
        ret = min(ret, sum + solve(idx + 5, dia-1, iron, stone, minerals));
    }
    if(iron){
        int sum = 0;
        for(int i = idx, j = 0; i+j<minerals.size()&&j<5; ++j)
            sum += pirodo[1][minerals[i+j]];
        ret = min(ret, sum + solve(idx + 5, dia, iron-1, stone, minerals));
    }
    if(stone){
        int sum = 0;
        for(int i = idx, j = 0; i+j<minerals.size()&&j<5; ++j)
            sum += pirodo[2][minerals[i+j]];
        ret = min(ret, sum + solve(idx + 5, dia, iron, stone-1, minerals));
    }
    return ret;
}

int solution(vector<int> picks, vector<string> minerals) {
    memset(dp, -1, sizeof dp);
    vector<int> mineralNum;
    
    for(string& s: minerals){
        int num;
        if(s == "diamond") num = 0;
        else if(s == "iron") num = 1;
        else num = 2;
        mineralNum.push_back(num);
    }
    return solve(0, picks[0], picks[1], picks[2], mineralNum);
}