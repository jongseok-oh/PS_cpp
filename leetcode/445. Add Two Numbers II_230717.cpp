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
    ListNode* l1n[100];
    ListNode* l2n[100];
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int idx1 = -1;
        while(l1){
            l1n[++idx1] = l1;
            l1 = l1->next;
        }

        int idx2 = -1;
        while(l2){
            l2n[++idx2] = l2;
            l2 = l2->next;
        }

        ListNode* head = new ListNode();
        ListNode* ans = new ListNode();
        
        while(idx1 >= 0 || idx2 >= 0){
            ans->val += (idx1<0?0:l1n[idx1]->val) + (idx2<0?0:l2n[idx2]->val);

            head->val = ans->val/10;
            ans->val %= 10;

            head->next = ans;

            ans = head;
            head = new ListNode();

            --idx1; --idx2;
        }

        return ans->val?ans:ans->next;
    }
};