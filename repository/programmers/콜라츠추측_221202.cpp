#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long num = 1LL * n;
    
    while(num != 1 && answer++<=500){
        if(num&1) num = num*3 + 1;
        else num = num>>1;
    }
    
    if(answer >= 500) answer = -1;
    
    return answer;
}