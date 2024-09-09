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
    const int dy[4] = {0,1,0,-1};
    const int dx[4] = {1,0,-1,0};

    bool needDirChange(int y, int x, int m, int n, vector<vector<int>>& matrix){
        return y < 0 || y >= m || x < 0 || x >=n || matrix[y][x] != -1;
    }
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n ,-1));
        
        int ty = 0, tx = -1, dir = 0;
        while(head){
            while(head && !needDirChange(ty + dy[dir], tx + dx[dir], m, n, matrix)){
                ty += dy[dir]; tx += dx[dir];
                matrix[ty][tx] = head->val;
                head = head->next;
            }
            dir = (dir + 1)%4;
        }

        return matrix;
    }
};