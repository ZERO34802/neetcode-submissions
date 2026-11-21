/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;
        map<Node* ,Node*> mp;
        Node* newRoot = new Node(node->val);
        mp[node] = newRoot;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            //take the front
            Node* f = q.front();
            q.pop();

            vector<Node*> neighbors = f->neighbors;
            for(int i = 0;i < neighbors.size();i++) {
                if(mp.count(neighbors[i]) > 0) {
                    Node* neighbourCopy = mp[neighbors[i]];
                    Node* fCopy = mp[f];
                    fCopy->neighbors.push_back(neighbourCopy);
                }else {
                    Node* newNode = new Node(neighbors[i]->val);
                    mp[neighbors[i]] = newNode;
                    Node* parentCopy = mp[f];
                    parentCopy->neighbors.push_back(newNode);
                    q.push(neighbors[i]);
                }
            }
        }
        return newRoot;

    }
};
