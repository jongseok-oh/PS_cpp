#include <vector>
#include <iostream>

using namespace std;

vector<int> failureFunction(vector<int>& nums){
    int n = nums.size();
    vector<int> pi(n);
    for(int i = 1; i<n; ++i){
        int length = pi[i-1];
        while(length && nums[i] != nums[length]){
            length = pi[length-1];
        }
        if(nums[i] == nums[length]) ++length;
        pi[i] = length;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[n - i -1];
    }
    vector<int> pi = failureFunction(nums);

    int k = -1, p = -1;
    int _min = 1e9;
    for(int i = 0; i<n; ++i){
        int tk = n - 1 - i;
        int tp = i + 1 - pi[i];
        if(tk + tp < _min){
            _min = tk + tp;
            k = tk; p = tp;
        }
    }
    cout<<k<<" "<<p;
}