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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> num_cache(nums.begin(), nums.end());

        ListNode dummy(-1);
        ListNode* tail = &dummy;
        while(head){
            int val = head->val;
            if(!num_cache.count(val)){
                tail->next = new ListNode(val);
                tail = tail->next;
            }
            head = head->next;
        }

        return dummy.next;
    }
};