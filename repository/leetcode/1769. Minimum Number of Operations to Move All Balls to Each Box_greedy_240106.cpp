class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        int left = 0, lcnt = 0;
        int right = 0, rcnt = 0;
        for(int i = 0; i<n; ++i){
            rcnt += boxes[i] - '0';
            if(boxes[i] == '1') right += i + 1;
        }

        vector<int> ret(n);
        for(int i = 0; i<n; ++i){
            right -= rcnt;
            if(boxes[i] == '1') --rcnt;
            ret[i] = left + right;
            
            if(boxes[i] == '1') ++lcnt;
            left += lcnt;
        }

        return ret;
    }
};