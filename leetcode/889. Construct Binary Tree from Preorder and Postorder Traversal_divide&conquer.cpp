class Solution {
    TreeNode* construct(int& preIdx, int& postIdx, vector<int>& preorder, vector<int>& postorder){
        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        if(val != postorder[postIdx]){
            root->left = construct(preIdx, postIdx, preorder, postorder);
        }
        if(val != postorder[postIdx]){
            root->right = construct(preIdx, postIdx, preorder, postorder);
        }
        ++postIdx;
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIdx = 0, postIdx = 0;
        return construct(preIdx, postIdx, preorder, postorder);
    }
};