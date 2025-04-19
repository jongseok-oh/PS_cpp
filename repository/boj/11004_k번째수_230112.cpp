#include <iostream>
#include <algorithm>
using namespace std;

int n,k;

int arr[5000000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i =0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);
    cout<<arr[k-1];
}