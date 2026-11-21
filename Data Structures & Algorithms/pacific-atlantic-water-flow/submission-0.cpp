class Solution {
public: 

    int dx[4] = {0,-1,0,1};
    int dy[4] = {1,0,-1,0};

    vector<pair<int,int>> neighbours(int x,int y,vector<vector<int>>& heights) {
        vector<pair<int,int>> v;
        int n = heights.size(), m = heights[0].size();
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i] , ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && heights[nx][ny] >= heights[x][y])v.push_back(make_pair(nx,ny));
        }
        return v;
    }

    void runbfs(queue<pair<int,int>>& q,vector<vector<int>>& dist,vector<vector<int>>& h,vector<vector<int>>& vis) {
        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int x = p.first,y = p.second;
            cout << x << " " << y << endl;
            dist[x][y] = 1;

            if(vis[x][y])continue;
            vis[x][y] = 1;

            for(auto [nx,ny]: neighbours(x,y,h)) {
                if(vis[nx][ny] == 0)q.push({nx,ny});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(),m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> distp(n,vector<int>(m,0));
        vector<vector<int>> dista(n,vector<int>(m,0));
        vector<vector<int>> visa(n,vector<int>(m,0));
        vector<vector<int>> visp(n,vector<int>(m,0));
        queue<pair<int,int>> qp,qa;
        for(int i = 0;i < n;i++)qp.push({i,0});
        for(int i = 1;i < m;i++)qp.push({0,i});
        for(int i = 0;i < m;i++)qa.push({n - 1,i});
        for(int i = 0;i < n - 1;i++)qa.push({i,m - 1});

        runbfs(qa,dista,heights,visa);
        runbfs(qp,distp,heights,visp);

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(dista[i][j] == 1 && distp[i][j] == 1) {
                    vector<int> temp;
                    temp.push_back(i);temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
