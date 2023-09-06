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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        auto cur = head;

        int len = 0;
        while(cur) ++len, cur = cur->next;

        int equity = len/k, surplus = len%k;

        vector<ListNode*> ans(k, 0);

        cur = head;
        ListNode* prev = 0;
        for(int i = 0; i<k && cur; ++i, --surplus){
            ans[i] = cur;

            for(int cnt = 0; cnt<equity + (surplus > 0) -1; cnt++)
                cur = cur->next;

            auto temp = cur->next;
            cur->next = 0;
            cur = temp;
        }

        return ans;
    }
};