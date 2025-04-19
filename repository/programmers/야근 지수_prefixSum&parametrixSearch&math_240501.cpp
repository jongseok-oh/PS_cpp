#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int calcDiff(int n, int mid, vector<int>& prefixSum, vector<int>& works){
    int _size = works.size();
    int idx = lower_bound(works.begin(), works.end(), mid) - works.begin();

    return prefixSum[_size] - prefixSum[idx] - (_size - idx) * mid;
}

long long solution(int n, vector<int> works) {
    sort(works.begin(), works.end());
    int _size = works.size();

    vector<int> prefixSum(_size + 1);

    for(int i = 0; i<_size; ++i)
        prefixSum[i + 1] = prefixSum[i] + works[i];

    int low = -1, high = 50000;
    while(low + 1 < high){
        int mid = (low + high)>>1;
        if(calcDiff(n, mid, prefixSum, works) <= n)
            high = mid;
        else low = mid;
    }

    int remain = n - calcDiff(n, high, prefixSum, works);

    long long ret = 0;
    for(int work: works){
        long long realWork = min(work, high);
        if(realWork == high && remain){
            realWork--; remain--;
        }
        if(realWork > 0) ret += realWork * realWork;
    }
    return ret;
}