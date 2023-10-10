#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    sort(data.begin(), data.end(), [&](const auto& a, const auto& b){
       return a[col-1] < b[col-1] || (a[col-1] == b[col-1] && a[0]>b[0]);
    });
    
    int ret = 0;
    for(int i = row_begin; i<=row_end; ++i){
        int sum = 0;
        for(int& num : data[i-1])
            sum += num%i;
        ret ^= sum;
    }
    
    return ret;
}