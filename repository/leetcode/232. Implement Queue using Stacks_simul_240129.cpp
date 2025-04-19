class MyQueue {
    int stack[100];
    int f = 0, t = 0;
public:
    MyQueue() {}
    
    void push(int x) {
        stack[t++] = x;
    }
    
    int pop() {
        return stack[f++];
    }
    
    int peek() {
        return stack[f];
    }
    
    bool empty() {
        return f == t;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */