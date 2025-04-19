#include <iostream>
#include <cstring>

using namespace std;

int n;
bool front[5000], flip[5000];

int calc(int k){
    memset(flip, 0, n);
    
    int sum = 0, ret = 0;
    for(int i = 0; i<=n -k; ++i){
        if((sum + front[i]) % 2 == 0){
            ++ret;
            flip[i] = true;
        }
        sum += flip[i];
        if(i - k + 1>= 0){
            sum -= flip[i - k + 1];
        }
    }

    for(int i = n - k + 1; i<n; ++i){
        if((front[i] + sum) % 2 == 0)
            return -1;
        
        if(i - k + 1>= 0){
            sum -= flip[i - k + 1];
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 0; i<n; ++i){
        char c; cin>>c;
        front[i] = c == 'F';
    }

    for(int i = n; i>=1; --i){
        int M = calc(i);
        if(M != -1){
            cout<<i<<" "<<M;
            return  0;
        }
    }
}