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
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a% b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp->next){
            int _gcd = gcd(temp->val, temp->next->val);
            
            ListNode* _next = temp->next;
            ListNode* gcdNode = new ListNode(_gcd, _next);
            temp->next = gcdNode;

            temp = _next;
        }

        return head;
    }
};