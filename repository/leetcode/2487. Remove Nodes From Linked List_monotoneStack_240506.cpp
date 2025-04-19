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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> stack;

        while(head){
            int val = head->val;
            while(stack.size() && stack.back()->val < val) stack.pop_back();
            stack.push_back(head);
            head = head->next;
        }

        for(int i = 0, n = stack.size()-1; i<n; ++i)
            stack[i]->next = stack[i+1];
        
        stack.back()->next = 0;

        return stack[0];
    }
};