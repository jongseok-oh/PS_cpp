class Solution {
    using ll = long long;
    class SegmentTree{
        int _n;
        vector<int> tree;
        
        void update(int idx, int value, int node, int s, int e){
            if(e < idx || s > idx) return;
            if(s == e) {
                tree[node] = value;
                return;
            }
            int mid = (s + e)>>1;
            update(idx, value, node*2, s, mid);
            update(idx, value, node*2+1, mid+1, e);

            tree[node] = tree[node*2] + tree[node*2+1];
        }

        int getSum(int node, int f, int t, int s, int e){
            if(f > e || t< s) return 0;
            if(s <= f && t <= e) return tree[node];
            int mid = (f + t)>>1;

            return getSum(node*2, f, mid, s, e) + getSum(node*2+1, mid+1, t, s, e);
        }
    public:
        SegmentTree(int n){
            _n = n;
            tree.resize(4*_n);
        }
        void update(int idx, int value){
            update(idx, value, 1, 0, _n - 1);
        }
        int getSum(int s, int e){
            return getSum(1, 0, _n-1, s, e);
        }
    };
public:
    ll goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> numMapper(n), numIdx(n);
        for(int i = 0; i<n; ++i) numMapper[nums1[i]] = i;
        for(int i = 0; i<n; ++i) numIdx[i] = numMapper[nums2[i]];

        SegmentTree st(n);
        ll ret = 0;
        for(int i = 0; i<n-1; ++i){
            int idx = numIdx[i];
            int leftCnt = st.getSum(0, idx);
            int rightCnt = n -(i + 1) - (idx - leftCnt);

            ret += (ll)leftCnt * rightCnt;
            st.update(idx, 1);
        }

        return ret;
    }
};