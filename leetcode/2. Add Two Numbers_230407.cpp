class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while(temp){
            if(l1){
                temp->val += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                temp->val += l2->val;
                l2 = l2->next;
            }

            if(temp->val >= 10 || l1 || l2){
                temp->next = new ListNode();
                temp->next->val += temp->val/10;
                temp->val %= 10;
            }
            temp = temp->next;
        }
        return ans;
    }
};