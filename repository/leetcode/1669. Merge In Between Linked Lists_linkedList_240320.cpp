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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* node = list1;
        
        ListNode* aPrevNode;
        ListNode* bAfterNode;
        for(int i = 0; i<=b+1; ++i){
            if(i == a - 1) aPrevNode = node;
            else if(i == b + 1) bAfterNode = node;
            node = node->next;
        }

        aPrevNode->next = list2;
        while(list2->next) list2 = list2->next;
        list2->next = bAfterNode;

        return list1;
    }
};