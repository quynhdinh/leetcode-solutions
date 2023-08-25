class Solution {
public:
    int R, C;
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd;
        TrieNode() : isEnd(false) {}
    };

    struct Trie {
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(string word) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isEnd = true;
        }
    };
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        R = board.size();
        C = board[0].size();
        for (string word : words) {
            trie.insert(word);
        }
        function<void(int, int, TrieNode*, string, vector<string>&)> dfs = [&](int i, int j, TrieNode* node, string currentWord, vector<string>& foundWords){
            if (i < 0 || i >= R || j < 0 || j >= C || board[i][j] == '#') {
                return;
            }
            char c = board[i][j];
            if (!node->children.count(c)) {
                return;
            }
            node = node->children[c];
            currentWord += c;
            if (node->isEnd) {
                foundWords.push_back(currentWord);
                node->isEnd = false; // Mark the word as found to avoid duplicates
            }
            char originalChar = board[i][j];
            board[i][j] = '#';
            for(int dir = 0; dir < 4; dir++){
                int r2 = dx[dir] + i;
                int c2 = dy[dir] + j;
                dfs(r2, c2, node, currentWord, foundWords);
            }
            board[i][j] = originalChar;    
        };
        vector<string> foundWords;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                dfs(i, j, trie.root, "", foundWords);
            }
        }
        return foundWords;
    }
};
