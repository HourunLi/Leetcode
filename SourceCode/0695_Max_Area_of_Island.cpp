class Solution {
private:
    int n, m;
    int dx[4]= {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    int max(int a, int b) {
        return a < b ? b : a;
    }
    int dfs(int area, int x, int y, vector<vector<int>>& grid) {
        grid[x][y] = -1;
        area++;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx < n && ny >=0 && ny < m && grid[nx][ny] == 1) {
                area = dfs(area, nx, ny, grid);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_ = 0;
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 1) continue;
                max_ = max(max_, dfs(0, i, j, grid));
            }
        }
        return max_;
    }
};