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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        int prev1, prev2;
        prev1 = temp->val; temp = temp->next;
        prev2 = temp->val; temp = temp->next;
        
        vector<int> idx;
        for(int i = 2; temp; temp = temp->next, ++i){
            int tVal = temp->val;
            if(prev2 > prev1 && prev2 > tVal
            || prev2 < prev1 && prev2 < tVal){
                idx.push_back(i-1);
            }
            prev1 = prev2;
            prev2 = tVal;
        }
        if(idx.size() <2) return {-1,-1};

        vector<int> ret(2, 1e9);
        ret[1] = idx.back() - idx.front();
        for(int i = 0; i<idx.size()-1; ++i){
            ret[0] = min(ret[0], idx[i + 1] - idx[i]);
        }
        return ret;
    }
};