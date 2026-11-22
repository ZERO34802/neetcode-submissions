class Solution {
public:
    struct node {
        int pref;
        vector<string> wordsend;
        node* child[26];
        node() {
            pref = 0;
            for(int i = 0;i < 26;i++) {
                child[i] = nullptr;
            }
        }
    };

        struct trie {
            node* root;
            trie () {
                root = new node();
            }

            void insert(string s) {
                node* curr = root;
                for(int i = 0;i < s.size();i++) {
                    curr->pref++;
                    if(curr->child[s[i] - 'a'] == nullptr) {
                        curr->child[s[i] - 'a'] = new node();
                    }
                    curr = curr->child[s[i] - 'a'];
                }
                curr->pref++;
                curr->wordsend.push_back(s);
            }
        };

    vector<pair<int,int>> neighbours(int x,int y,vector<vector<char>>& board,vector<vector<int>>& vis) {
        int n = board.size(),m = board[0].size();
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        vector<pair<int,int>> v;
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i],ny = y + dy[i];
            if(nx < n && nx >= 0 && ny < m && ny >= 0 && vis[nx][ny] != 1) {
                v.push_back({nx,ny});
            } 
        }
        return v;
    }
    
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis, set<string>& ans,node* curr) {
        int n = board.size(), m = board[0].size();
        if(i >= n || i < 0 || j >= m || j < 0)return;

        if(curr) {
            if(curr->wordsend.size() > 0) {
                ans.insert(curr->wordsend[0]);
            }

            vis[i][j] = 1;
            for(auto [nx,ny] : neighbours(i,j,board,vis)) {
                if(curr->wordsend.size() > 0 && curr->wordsend[0] == "back") {
                    cout << i << " " << j << " : " << nx << " " << ny << "\n";
                    cout << board[i][j] << "\n";
                }
                if(curr->child[board[nx][ny] - 'a'] != nullptr)dfs(nx,ny,board,vis,ans,curr->child[board[nx][ny] - 'a']);
            }
            vis[i][j] = 0;
        }else {
            return;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(),m = board[0].size();
        trie tt = trie();
        for(int i = 0;i < words.size();i++) {
            tt.insert(words[i]);
        }
        set<string> ans;
        vector<vector<int>> vis(n,vector<int>(m,0));
        node* curr = tt.root;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(curr->child[board[i][j] - 'a'] != nullptr)dfs(i,j,board,vis,ans,curr->child[board[i][j] - 'a']);
            }
        }
        vector<string> t;
        for(auto it : ans)t.push_back(it);
        return t;
    }
};
