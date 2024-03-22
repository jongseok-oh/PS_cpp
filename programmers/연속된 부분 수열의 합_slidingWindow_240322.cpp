#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> ret = {(int)1e9, (int)(2*1e9)};
    int n = sequence.size();
    
    int sum = 0;
    for(int i = 0, j = 0; i<n; ++i){
        while(j < n && sum < k) sum += sequence[j++];
        
        if(sum == k && ret[1] - ret[0] > j - i - 1){
            ret[1] = j-1; ret[0] = i ;
        }
        sum -= sequence[i];
    }
    return ret;
}