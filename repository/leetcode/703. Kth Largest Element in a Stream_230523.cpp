class KthLargest {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right; 
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) add(num);
    }
    
    int add(int val) {
        right.push(val);
        if(right.size() > k){
            left.push(right.top());
            right.pop();
        }
        return right.top();
    }
};