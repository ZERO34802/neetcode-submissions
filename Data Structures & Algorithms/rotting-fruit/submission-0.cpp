class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    vector<pair<int,int>>  neighbours(int x,int y,vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> v;
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < n && ny < m && nx >= 0 && ny >= 0 && grid[nx][ny] == 1)v.push_back(make_pair(nx,ny));
        }
        return v;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int freshOranges = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(grid[i][j] == 1)freshOranges++;
                else if(grid[i][j] == 2) {
                    q.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        int maxTime = 0;
        while(!q.empty()) {
            auto p =q.front();
            q.pop();

            int i = p.first.first, j = p.first.second;
            int time = p.second;

            time += 1;
            for (auto [x, y] : neighbours(i,j,grid)) {
                freshOranges -= 1;
                maxTime = max(time,maxTime);

                grid[x][y] = 2;
                q.push(make_pair(make_pair(x,y),time));
            }
        }
        if(freshOranges > 0)return -1;
        else return maxTime;
    }
};
