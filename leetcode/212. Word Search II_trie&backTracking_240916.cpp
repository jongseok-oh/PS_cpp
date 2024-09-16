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
            unordered_map<char, Node*> childs;
            bool isEnd = false;
            string origin;
        };

        Node* head = new Node();
        void insert(const string& str){
            if(str.empty()) return;
            
            Node* temp = head;
            for(char c : str){
                if(!(temp->childs.count(c))) temp->childs[c] = new Node();
                temp = temp->childs[c];
            }
            temp->isEnd = true;
            temp->origin = str;
        }
    };

    const int dy[4] = {1,0,-1,0}, dx[4] = {0,1,0,-1};
    void dfs(int y, int x, Trie::Node* parent, vector<vector<char>>& board, unordered_set<string>& ret)
    {
        char tChar = board[y][x];

        auto tNode = parent->childs[tChar];
        if(tNode->isEnd){
            ret.emplace(tNode->origin);
        }

        board[y][x] = '#';
        int n = board.size(), m = board[0].size();
        for(int dir = 0; dir<4; ++dir){
            int ny = y + dy[dir], nx = x + dx[dir];
            if(ny < 0 || ny>=n || nx < 0 || nx >= m || board[ny][nx] == '#' || !(tNode->childs.count(board[ny][nx]))) continue;
            dfs(ny, nx, tNode, board, ret);
        }
        board[y][x] = tChar;

        if(tNode->childs.empty()){
            parent->childs.erase(tChar);
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();

        Trie trie;
        for(string& word : words) {
            if(word.size() > n*m) continue;
            trie.insert(word);
        }

        unordered_set<string> ret;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if((trie.head->childs.count(board[i][j]))){
                    dfs(i,j, trie.head, board, ret);
                }
            }
        }

        return {ret.begin(), ret.end()};
    }
};