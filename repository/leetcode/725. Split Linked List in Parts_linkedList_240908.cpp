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
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            ++cnt;
            temp = temp->next;
        }
        
        int each = cnt/k, remain = cnt%k;

        vector<ListNode*> ret(k);
        for(auto& node : ret){
            int tcnt = each;
            if(remain > 0){
                --remain; tcnt++;
            }
            node = head;
            ListNode* prev = nullptr;
            while(tcnt--){
                prev = head;
                head = head->next;
            }
            if(prev) prev->next = nullptr;
        }

        return ret;
    }
};