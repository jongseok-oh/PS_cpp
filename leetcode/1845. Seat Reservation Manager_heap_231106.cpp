class SeatManager {
    priority_queue<int, vector<int>, greater<int>> q;
public:
    SeatManager(int n) {
        for(int i = 1; i<=n; ++i) q.push(i);
    }
    
    int reserve() {
        int t = q.top(); q.pop();
        return t;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */