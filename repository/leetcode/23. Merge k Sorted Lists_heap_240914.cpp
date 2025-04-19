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
    using pii = pair<int, int>;

    void insertQ(vector<ListNode*>& lists, int i, priority_queue<pii, vector<pii>, greater<>>& q){
        ListNode* listNode = lists[i];
        if(listNode){
            q.emplace(listNode->val, i);
            lists[i] = listNode->next;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> tempLists = lists;
        
        priority_queue<pii, vector<pii>, greater<>> q;
        for(int i = 0, n = tempLists.size(); i<n; ++i){
            insertQ(tempLists, i, q);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(q.size()){
            auto [minVal, listIdx] = q.top(); q.pop();

            // tail 갱신
            tail->next = new ListNode(minVal);
            tail = tail ->next;

            insertQ(tempLists, listIdx, q);
        }

        return dummy->next;
    }
};