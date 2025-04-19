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
    ListNode* doubleIt(ListNode* head) {
        vector<ListNode*> vec;

        vec.push_back(new ListNode(0));
        vec[0]->next = head;

        while(head){
            head->val *= 2;
            vec.push_back(head);
            head = head->next;
        }

        int n = vec.size();
        for(int i = n-1; i>0; --i){
            ListNode* node = vec[i];
            int val = node->val;

            node->val = val%10;
            vec[i-1]->val += val/10;
        }

        return vec[0]->val == 0? vec[1] : vec[0];
    }
};