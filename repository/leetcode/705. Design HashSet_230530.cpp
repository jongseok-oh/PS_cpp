class MyHashSet {
    bool __set[1000001];
public:
    MyHashSet() {memset(__set, 0, sizeof(__set));}
    
    void add(int key) {
        __set[key] = true;
    }
    
    void remove(int key) {
        __set[key] = false;
    }
    
    bool contains(int key) {
        return  __set[key];
    }
};