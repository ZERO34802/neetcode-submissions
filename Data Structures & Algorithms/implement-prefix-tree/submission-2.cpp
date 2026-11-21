struct node {
    int pref;
    int ends;
    node* child[26];
    node() {
        pref = ends = 0;
        for(int i = 0;i < 26;i++) {
            child[i] = nullptr;
        }
    }
};

class PrefixTree {
public:
    node* root;
    PrefixTree() {
        root = new node();
    }
    
    void insert(string s) {
        string word = s;
        node* curr = root;
        for(int i = 0;i < word.size();i++) {
            curr->pref++;
            if(curr->child[word[i] - 'a'] == nullptr) {
                curr->child[word[i] - 'a'] = new node();
            }
            curr = curr->child[word[i] - 'a'];
        }
        curr->ends += 1;
    }
    
    bool search(string word) {
        node* curr = root;
        for(int i = 0;i < word.size();i++) {
            if(curr->child[word[i] - 'a'] == nullptr)return false;
            curr = curr->child[word[i] - 'a'];
        }
        if(curr->ends > 0)return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        node* curr = root;
        for(int i = 0;i < prefix.size();i++) {
            if(curr->child[prefix[i] - 'a'] == nullptr)return false;
            curr = curr->child[prefix[i] - 'a'];
        }
        if(curr->pref > 0 || curr->ends > 0)return true;
        else return false;
    }
};
