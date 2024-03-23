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
    void reorderList(ListNode* head) {
        vector<ListNode*> cache;
        while(head) {
            cache.push_back(head);
            head = head->next;
        }
        int n = cache.size();
        ListNode* cur = cache[0];
        for(int i = 1, j = n-1; i <=j; ++i, --j){
            cur->next = cache[j];
            cur = cache[j];
            cur->next = 0;

            if(i < j){
                cur->next = cache[i];
                cur = cache[i];
                cur->next = 0;
            }
        }
    }
};