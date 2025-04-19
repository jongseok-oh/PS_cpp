/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        --left; --right;

        vector<ListNode*> cache;

        auto cur = head;

        while(cur) {
            cache.push_back(cur);
            cur = cur->next;
        }

        auto tail = cache[right]->next;
        for(int i = right; i>left; --i) cache[i]->next=cache[i-1];
        
        cache[left]->next = tail;
        if(left) cache[left - 1]->next = cache[right];

        return !left?cache[right]:cache[0];
    }
};