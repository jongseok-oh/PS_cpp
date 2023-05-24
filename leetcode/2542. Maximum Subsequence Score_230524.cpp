class Solution {

struct Pair{int one, two;};

public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<Pair> pairs(n);

        for(int i = 0; i<n; i++) pairs[i] = {nums1[i], nums2[i]};
        
        sort(pairs.begin(), pairs.end(), [](const Pair& a, const Pair& b){
            return a.two > b.two;
        });

        priority_queue<int, vector<int>, greater<int>> q;
        long long ret = -1, tsum = 0;
        for(int i = 0; i<n; i++){
            q.push(pairs[i].one);
            tsum += pairs[i].one;

            if(q.size() > k){
                tsum -= q.top();
                q.pop();
            }
            if(q.size() == k) ret = max(ret, tsum * pairs[i].two);
        }
        return ret;
    }
};