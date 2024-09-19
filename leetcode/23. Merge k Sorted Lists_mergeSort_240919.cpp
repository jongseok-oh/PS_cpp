class Solution {
    ListNode* mergLists(int l, int r, vector<ListNode*>& lists){
        if(l == r) return lists[l];
        int mid = (l + r)>>1;
        ListNode* left = mergLists(l, mid, lists);
        ListNode* right = mergLists(mid+1, r, lists);

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(left || right){
            if(left == NULL || (right != NULL && (left->val > right->val))){
                tail->next = right;
                tail = tail->next;
                right = right->next;
            }else{
                tail->next = left;
                tail = tail->next;
                left = left->next;
            }
        }

        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        return mergLists(0, n-1, lists);
    }
};