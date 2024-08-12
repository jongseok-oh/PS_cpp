class KthLargest {
    int _k;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(int num : nums) add(num);
    }
    
    int add(int val) {
        if(right.size() < _k){
            right.push(val);
            return right.top();
        }else{
            right.push(val);
            int _top = right.top(); right.pop();
            left.push(_top);
            return right.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */