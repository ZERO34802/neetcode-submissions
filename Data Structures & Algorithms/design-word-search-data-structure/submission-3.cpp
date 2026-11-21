struct node {
    int pref;
    int end;
    node* child[26];
    node() {
        pref = end = 0;
        for(int i =0;i < 26;i++) {
            child[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    node* root;
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* curr = root;
        for(int i = 0;i < word.size();i++) {
            curr->pref++;
            if(curr->child[word[i] - 'a'] == nullptr) {
                curr->child[word[i] - 'a'] = new node();
            }
            curr = curr->child[word[i] - 'a'];
        }
        curr->end += 1;
    }
    
    bool rec(int level,string& word,node* curr) {
        if(level == word.size()) {
            if(curr->end > 0)return true;
            return false;
        }

        bool ans = false;
        if(word[level] == '.') {
            for(int i = 0;i < 26;i++) {
                if(curr->child[i] != nullptr) {
                    ans = ans | (rec(level + 1,word,curr->child[i]));
                }
            }
        }else {
            if(curr->child[word[level] - 'a'] != nullptr) {
                ans = ans | (rec(level + 1,word,curr->child[word[level] - 'a']));
            }
        }

        return ans;
    }

    bool search(string word) {
        node* curr = root;
        bool find = rec(0,word,curr);
        return find;
    }
};
