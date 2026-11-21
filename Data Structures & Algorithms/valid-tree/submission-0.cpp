class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != (n - 1))return false;
        if(n == 1 && edges.size() == 0)return true;

        vector<vector<int>> g(n);
        for(int i = 0;i < edges.size();i++) {
            int a = edges[i][0], b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        queue<int> q;
        q.push(0);
        vector<int> vis(n);
        int count = 0;
        while(!q.empty()) {
            int f = q.front();
            q.pop();

            if(vis[f])continue;
            vis[f] = 1;
            count++;

            for(auto neighbours : g[f]) {
                q.push(neighbours);
            }
        }
        return count == n;
    }
};
