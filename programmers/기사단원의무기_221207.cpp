#include <math.h>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i =1; i<=number; i++){
        int sqr = (int)sqrt(i);
        int temp = 0;
        
        for(int j = 1; j<=sqr; j++) if(!(i%j)) temp++;
        
        temp = (sqr * sqr == i? temp*2 - 1:temp*2);
        answer += (temp>limit?power:temp);
    }
    return answer;
}