/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> cache;

        ListNode* cur = head;

        while(cur){
            if(cache.find(cur) != cache.end()) return true;
            cache.insert(cur);
            cur = cur->next;
        }
        
        return false;
    }
};
