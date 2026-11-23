class Node {
    public:
    Node* prev,*next;
    int key,val;
    Node(int k,int v) {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int,Node*> mp;
    Node* head, *tail;
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        cap = capacity;
        
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterhead(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        temp->prev = node;
        node->next = temp;
    }

    void deleteNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;

        node->next = nullptr;
        node->prev = nullptr;
    }
    
    int get(int key) {
        if(mp.count(key) == 1) {
            Node* n = mp[key];
            deleteNode(n);
            insertAfterhead(n);
            return n->val;
        }else return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key) == 1) {
            Node* n = mp[key];
            n->val = value;
            deleteNode(n);
            insertAfterhead(n);
        }else {
            if(mp.size() == cap) {
                Node* least = tail->prev;
                deleteNode(least);
                mp.erase(least->key);
                Node* newNode = new Node(key,value);
                mp[key] = newNode;
                insertAfterhead(newNode);
            }else {
                Node* newNode = new Node(key,value);
                mp[key] = newNode;
                insertAfterhead(newNode);
            }
        }
    }
};
