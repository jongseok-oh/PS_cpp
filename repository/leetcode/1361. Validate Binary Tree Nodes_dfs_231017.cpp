class Solution {
    int indegree[10000];

    int cnt = 0;
    bool solve(int tNode, vector<int>& leftChild, vector<int>& rightChild){
        indegree[tNode] = -1;
        ++cnt;
        int left = leftChild[tNode], right = rightChild[tNode];

        if(left != -1)
            if(indegree[left] == -1 || !solve(left, leftChild, rightChild))
                return false;
        
        if(right != -1)
            if(indegree[right] == -1 || !solve(right, leftChild, rightChild))
                return false;
        
        return true;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i = 0; i<n; ++i){
            int left = leftChild[i], right = rightChild[i];

            if(left != -1) ++indegree[left];
            if(right != -1) ++indegree[right];
        }

        int top = -1;
        for(int i = 0; i<n; ++i){
            if(!indegree[i]){
                if(top != -1) return false;
                top = i;
            }
        }

        if(top == -1) return false;
        return solve(top, leftChild, rightChild) && cnt == n;
    }
};