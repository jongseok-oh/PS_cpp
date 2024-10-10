class Solution {
    class SegmentTree{
    public:
        SegmentTree(){
            tree = vector<int> (2 * 1e5, 1e9);
        }
        void insert(int idx, int num){
            insert(1, 0, 5 * 1e4, num ,idx);
        }
        int getIdx(int num){
            return getIdx(1, 0, 5 * 1e4, num);
        }
    private:
        vector<int> tree;
        void insert(int node, int l, int r, int num, int idx){
            if(l > num || r < num) return;
            if(l == r) {
                if(tree[node] == 1e9) tree[node] = idx;
                return;
            }
            int mid = (l + r)>>1;
            insert(node*2, l, mid, num, idx);
            insert(node*2 + 1, mid + 1, r, num, idx);
            tree[node] = min(tree[node*2], tree[node*2 + 1]);
        }
        int getIdx(int node, int l, int r, int num){
            if(l > num) return 1e9;
            if(r <= num) return tree[node];
            int mid = (l + r)>>1;
            return min(getIdx(node*2, l, mid, num), getIdx(node*2+1, mid+1, r, num));
        }
    };
public:
    int maxWidthRamp(vector<int>& nums) {
        SegmentTree tree;
        int ret = 0;
        for(int i = 0, n = nums.size(); i<n; ++i){
            int idx = tree.getIdx(nums[i]);
            if(idx != 1e9) ret = max(ret, i - idx);
            tree.insert(i, nums[i]);
        }
        return ret;
    }
};