#include <math.h>
#include <iostream>

using namespace std;

typedef long long ll;

ll solution(int k, int d) {
    ll answer = 0;
    
    int a = 0;
    ll radius = (1LL * d * d)/(1LL * k * k) ;
    while(true){
        ll asqr = 1LL * a * a;
        if(radius - asqr <0) break;
        answer += (int)sqrt(radius - asqr) + 1;
        a++;
    }
    return answer;
}