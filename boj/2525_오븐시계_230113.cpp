#include <iostream>

using namespace std;

int a,b,c;

int main(){
    cin>>a>>b>>c;
    
    b += c;
    a += b/60;
    b %= 60;
    a %= 24;
    cout<<a<<" "<<b;
}