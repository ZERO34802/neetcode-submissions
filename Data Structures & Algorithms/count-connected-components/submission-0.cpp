class Solution {
public:
    struct DisjointSet {
        int n,setSize;
        vector<int> parent;
        vector<int> rank;
        
        DisjointSet(int a) {
            n = a;
            setSize = a;
            parent.resize(a + 1);
            rank.resize(a + 1);

            for(int i = 0;i < a;i++)parent[i] = i;
            for(int i = 0;i < a;i++)rank[i] = 1;
        }

        int find(int x) {
            if(x == parent[x])return x;
            else return parent[x] = find(parent[x]);
        }

        void merge(int x,int y) {
            x = find(x); y = find(y);
            if(x != y) {
                if(rank[x] >= rank[y]) {
                    rank[x] += rank[y];
                    parent[y] = x;
                }else {
                    rank[y] += rank[x];
                    parent[x] = y;
                }
                setSize -= 1;
            }
        }
    };
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds = DisjointSet(n);
        for(int i = 0;i < edges.size();i++) {
            int a = edges[i][0], b = edges[i][1];
            ds.merge(a,b);
        }
        return ds.setSize;
    }
};
