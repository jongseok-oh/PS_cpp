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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;

        while(head){
            nodes.push_back(head);
            head = head->next;
        }

        int idx = nodes.size() - n;

        if(idx == 0) return nodes[idx]->next;
        if(nodes.size() - 1 == idx) nodes[idx-1]->next = 0;
        else nodes[idx-1]->next = nodes[idx+1];

        return nodes[0];
    }
};