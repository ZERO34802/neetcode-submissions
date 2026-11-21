class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> g(n + 1);
        for(int i = 0;i < n;i++) {
            int a = edges[i][0], b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
            queue<pair<int,int>> q;
            q.push({edges[0][0],-1});
            vector<int> vis(n + 1);
            while(!q.empty()) {
                int t = q.front().first, p = q.front().second;
                q.pop();

                if(vis[t])continue;
                vis[t] = 1;

                for(auto neighbor : g[t]) {
                    if(vis[neighbor] && neighbor != p) {
                        vector<int> temp;
                        temp.push_back(a);
                        temp.push_back(b);
                        return temp;
                    }else q.push({neighbor,t});
                }
            }
        }
    }
};
