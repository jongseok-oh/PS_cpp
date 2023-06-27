#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int numCnt;
int nums[101];
bool __plus[100];

// dp[i][j] i ~ j까지 괄호로 묶였을 때
// 최대, 최소 값
int dpMax[101][101];
int dpMin[101][101];

int solution(vector<string> arr)
{
    for(auto& s: arr){
        if(s == "-" || s == "+")
            __plus[numCnt-1] = (s == "+");
        else nums[numCnt++] = stoi(s);
    }
    
    for(int len = 0; len<numCnt; len++){
        for(int start = 0; start<numCnt - len; start++){
            int end = start + len;
            int& dMax = dpMax[start][end];
            int& dMin = dpMin[start][end];
            if(start == end){
                dMax = nums[start];
                dMin = nums[start];
                continue;
            }
            
            dMax = -1e9;
            dMin = 1e9;
            
            for(int mid = start; mid<end; mid++){
                if(__plus[mid]){
                    dMax = max(dMax, dpMax[start][mid] + dpMax[mid+1][end]);
                    dMin = min(dMin, dpMin[start][mid] + dpMin[mid+1][end]);
                }else{
                    dMax = max(dMax, dpMax[start][mid] - dpMin[mid+1][end]);
                    dMin = min(dMin, dpMin[start][mid] - dpMax[mid+1][end]);
                }
            }
        }
    }
    
    return dpMax[0][numCnt - 1];
}