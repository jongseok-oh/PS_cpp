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
    ListNode* cur;
    bool solve(ListNode* node){
        if(!node) return true;
        bool ret = solve(node->next) && (cur->val == node->val);
        cur = cur->next;
        return ret;
    }
public:
    bool isPalindrome(ListNode* head) {
        cur = head;
        return solve(head->next);
    }
};