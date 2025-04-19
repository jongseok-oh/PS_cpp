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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ret = new ListNode();
        ListNode* temp = ret;
        int sum = 0;
        for(ListNode* t = head; t; t = t->next){
            if(t->val == 0 && sum > 0){
                temp->next = new ListNode();
                temp = temp->next;
                temp->val = sum;
                sum = 0;
            }
            sum += t->val;
        }
        return ret->next;
    }
};