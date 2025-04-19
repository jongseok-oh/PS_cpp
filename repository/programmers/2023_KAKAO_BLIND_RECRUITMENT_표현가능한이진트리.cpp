#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int chk(string& t, int start, int end){
    if(start == end) return 1;
    int root = (start + end) >> 1;
    if(t[root] == '0' && (t[(start + root - 1)>>1] == '1'
                          ||t[(root + 1 + end)>>1] == '1')) return 0;
    return chk(t, start, root -1)&chk(t, root + 1, end);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(ll num: numbers){
        int maxBit = 63;
        
        while(!(num & (1LL << maxBit))) maxBit--;
        int saturatedBit = 1;
        while(saturatedBit - 1 < maxBit + 1) saturatedBit *= 2;
        
        int diff = saturatedBit - maxBit -2;
        string t;
        while(diff--) t.push_back('0');
        while(maxBit>=0) t.push_back('0' + ((bool)(num & (1LL << maxBit--))));
        answer.push_back(chk(t,0, t.size()-1));
    }
    return answer;
}