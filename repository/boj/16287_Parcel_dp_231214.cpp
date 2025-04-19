#include <iostream>
#include <algorithm>

using namespace std;

int w,n;
int arr[5000];
bool dp[400001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>w>>n;
    for(int i = 0; i<n; ++i) cin>>arr[i];

    sort(arr, arr + n);

    for(int i = 1; i<n-2; ++i){
        if(arr[i]>= w/2) break;
        for(int j = 0; j<i; ++j){
            int sum = arr[i] + arr[j];
            if(sum >= w/2) break;
            dp[sum] = true;
        }
        for(int k = i + 2; k<n; ++k){
            int tar = w - arr[i + 1] - arr[k];
            if(tar <= 0 || tar > 400000) break;
            if(dp[tar]){
                cout<<"YES"; return 0;
            }
        }
    }

    cout<<"NO";
}