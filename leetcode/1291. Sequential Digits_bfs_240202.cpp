class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ret;
        queue<long long> q;

        for(int i = 1; i<10; ++i) q.push(i);

        while(q.size()){
            long long t = q.front(); q.pop();

            if(t >= low) ret.push_back(t);
        
            long long next = t*10 + t%10 + 1;
            if(t%10 != 9 && next<=high) q.push(next);
        }

        sort(ret.begin(), ret.end());
        return ret;
    }
};