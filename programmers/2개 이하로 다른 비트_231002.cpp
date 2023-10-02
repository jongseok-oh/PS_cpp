#include <string>
#include <vector>

using namespace std;

long long f(long long num){
    int bit = 0;
    
    while(true){
        // 현재 비트 1, 다음 비트 0
        if(num & (1LL<<bit) && !(num & (1LL<<(bit + 1)))){
            return num + (1LL<<bit);
        }else if(!(num & (1LL<<bit)))
            return num ^ (1LL<<bit);
        ++bit;
    }
    
    return -1;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto& num : numbers)
        answer.push_back(f(num));
    
    return answer;
}