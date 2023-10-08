#include <string>
#include <vector>

typedef long long ll;

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    ll q1Sum = 0, q2Sum = 0;
    for(int& num: queue1) q1Sum += num;
    for(int& num: queue2) q2Sum += num;
    
    if(q1Sum == q2Sum) return 0;
    
    ll tar = 0;
    tar = (q1Sum + q2Sum) >>1;
    
    int cnt = 0;
    
    vector<int> total;
    total.insert(total.end(), queue1.begin(), queue1.end());
    total.insert(total.end(), queue2.begin(), queue2.end());
    
    int left = 0, right = queue1.size();
    
    while(left <= right && right < total.size()){
        if(q1Sum < tar) q1Sum += total[right++];
        else q1Sum -= total[left++];
        
        ++cnt;
        
        if(q1Sum == tar) return cnt;
    }
    
    return -1;
}