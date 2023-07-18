class LRUCache {
    int cap;
    int cnt = 0;

    struct Node{
        Node* prev;
        Node* next;
        int key;

        Node(int key){
            this->key = key;
        }
    };

    Node* nodes[10001];
    int keys[10001];

    Node* head;
    Node* tail;

    void remove(int key){
        Node* tnode = nodes[key];
        if(!tnode){
            //cout<<"key : "<<key<<" remove null"<<"\n";
            return;
        }
        tnode->prev->next = tnode->next;
        tnode->next->prev = tnode->prev;
        nodes[key] = 0;
    }

    void insert(int key){
        Node* tnode = new Node(key);

        tail->prev->next = tnode;
        tnode->prev = tail->prev;
        tail->prev = tnode;
        tnode->next = tail;

        nodes[key] = tnode;
    }

    void setCache(int key){
        remove(key);
        insert(key);
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        memset(keys, -1, sizeof keys);
        memset(nodes, 0, sizeof nodes);
        head = new Node(-1);
        tail = new Node(-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        int ret = keys[key];
        if(ret != -1) setCache(key);
        return ret;
    }
    
    void put(int key, int value) {
        if(keys[key] != -1){
            setCache(key);
            keys[key] = value;
        }else{
            if(cnt == cap){
                int tkey = head->next->key;
                remove(tkey);
                keys[tkey] = -1;
                
                insert(key);
                keys[key] = value;
            }else{
                insert(key);
                ++cnt;
                keys[key] = value;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */