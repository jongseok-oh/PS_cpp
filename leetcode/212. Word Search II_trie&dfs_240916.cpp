class Solution {
    // naive approach
    // for each words -> search board
    // O(30000) * O(3^10 * 144)

    // Improve search board int O(1)
    // cache all of words that can be find in board
    // how to cache these?

    // naive -> 3^10 * 144 * (10 * 9 / 2) {all substring}
    // Trie -> 3^10 * 144 * 10 -> 85Mb

    struct Trie{
    public:
        struct Node{
            Node* childs[26];
        };
        void insert(const string& str){
            if(str.empty()) return;
            
            Node* temp = head;
            for(char c : str){
                Node* &child = temp->childs[c - 'a'];
                if(child == nullptr) child = new Node();
                temp = child;
            }
        }
        bool isContain(const string& str){
            Node* temp = head;
            for(char c : str){
                Node* &child = temp->childs[c - 'a'];
                if(child == nullptr) return false;
                temp = child;
            }

            return true;
        }
    private:
        Node* head = new Node();
    };

    const int dy[4] = {1,0,-1,0}, dx[4] = {0,1,0,-1};
    void dfs(int y, int x, string& str, vector<vector<char>>& board, vector<vector<bool>>& visit, Trie& trie){
        if(str.size() == 10){return;}
        
        str.push_back(board[y][x]);
        trie.insert(str);

        int n = board.size(), m = board[0].size();
        for(int dir = 0; dir<4; ++dir){
            int ny = y + dy[dir], nx = x + dx[dir];
            if(ny < 0 || ny>=n || nx < 0 || nx >= m || visit[ny][nx]) continue;
            visit[ny][nx] = true;
            dfs(ny,nx,str,board,visit,trie);
            visit[ny][nx] = false;
        }

        str.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m));

        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                visit[i][j] = true;
                string temp = "";
                dfs(i, j, temp, board, visit, trie);
                visit[i][j] = false;
            }
        }

        vector<string> ret;
        for(string& str : words){
            if(trie.isContain(str)){
                ret.emplace_back(str);
            }
        }

        return ret;
    }
};