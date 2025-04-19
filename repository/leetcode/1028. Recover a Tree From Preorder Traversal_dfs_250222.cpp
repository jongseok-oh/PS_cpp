class Solution {
    TreeNode* parse(int& idx, int level, const string& traversal){
        int dash = 0, n = traversal.size();
        while(idx + dash < n && traversal[idx + dash] == '-'){
            ++dash;
        }
        if(dash != level) return nullptr;
        idx += dash;

        int value = 0;
        while(idx < n && traversal[idx] != '-'){
            value *= 10;
            value += traversal[idx++] - '0';
        }
        TreeNode* node = new TreeNode(value);
        node->left = parse(idx, level + 1, traversal);
        node->right = parse(idx, level + 1, traversal);

        return node;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0;
        return parse(idx, 0, traversal);
    }
};