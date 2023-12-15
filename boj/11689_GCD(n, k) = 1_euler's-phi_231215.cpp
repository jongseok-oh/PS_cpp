#include <iostream>
#include <math.h>

typedef long long ll;

using namespace std;

ll n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;

    ll ret = 1;
    ll _end = sqrt(n);
    for(int i = 2; n != 1 &&i<=_end; ++i){
        
        ll temp = 1;
        while(n != 1 && n % i == 0){
            temp *= i;
            n /= i;
        }
        if(temp != 1) ret *= temp / i * (i - 1);
    }
    if(n > 1) ret *= n - 1;
    cout<<ret;
}