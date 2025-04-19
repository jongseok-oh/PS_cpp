/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> cache;
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* cur = head;

        while(cur){
            cache[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;

        while(cur){
            cache[cur]->next = cache[cur->next];
            cache[cur]->random = cache[cur->random];
            cur = cur->next;
        }

        return cache[head];
    }
};