class Node {
public:
    int freq;
    Node* prev;
    Node* next;
    unordered_set<string> keys;
};

class AllOne {
private:
    Node* head;
    Node* tail;
    unordered_map<string, Node*> map;
    Node nodePool[50002];
    int unused;

    Node* getNewNode(int freq){
        Node* node = &nodePool[unused++];
        node->freq = freq;
        return node;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
public:
    AllOne() {
        unused = 0;
        head = getNewNode(0);
        tail = getNewNode(0);
        head->next = tail;
        tail->prev = head;
    }
    void inc(string key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            int freq = node->freq;
            node->keys.erase(key);

            Node* nextNode = node->next;
            if (nextNode == tail || nextNode->freq != freq + 1) {
                Node* newNode = getNewNode(freq + 1);
                newNode->keys.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
                node->next = newNode;
                nextNode->prev = newNode;
                map[key] = newNode;
            } else {
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }

            if (node->keys.empty()) {
                removeNode(node);
            }
        } else {
            Node* firstNode = head->next;
            if (firstNode == tail || firstNode->freq > 1) {
                Node* newNode = getNewNode(1);
                newNode->keys.insert(key);
                newNode->prev = head;
                newNode->next = firstNode;
                head->next = newNode;
                firstNode->prev = newNode;
                map[key] = newNode;
            } else {
                firstNode->keys.insert(key);
                map[key] = firstNode;
            }
        }
    }

    void dec(string key) {
        if (map.find(key) == map.end()) {
            return;
        }

        Node* node = map[key];
        node->keys.erase(key);
        int freq = node->freq;

        if (freq == 1) {
            map.erase(key);
        } else {
            Node* prevNode = node->prev;
            if (prevNode == head || prevNode->freq != freq - 1) {
                Node* newNode = getNewNode(freq - 1);
                newNode->keys.insert(key);
                newNode->prev = prevNode;
                newNode->next = node;
                prevNode->next = newNode;
                node->prev = newNode;
                map[key] = newNode;
            } else {
                prevNode->keys.insert(key);
                map[key] = prevNode;
            }
        }

        if (node->keys.empty()) {
            removeNode(node);
        }
    }

    string getMaxKey() {
        if (tail->prev == head) {
            return "";
        }
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail) {
            return "";
        }
        return *(
            head->next->keys
                .begin());
    }
};