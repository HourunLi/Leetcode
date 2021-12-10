#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int n, m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if(grid[x][y] != 1) return;
        grid[x][y] = 2;
        for(int k = 0; k < 4; k++) {
            int tx = x+dx[k];
            int ty = y+dy[k];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || grid[tx][ty]!= 1) continue;
            dfs(grid, tx, ty);
        }
        return;
    }

    int isConnected(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 1) continue;
                cnt++;
                dfs(grid, i, j);
            }
        }
        //recover
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                grid[i][j] = grid[i][j] == 2 ? 1 : grid[i][j];

        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(isConnected(grid) != 1) return 0;
        int num=0;
        bool flag = false;
        int** map = (int **) malloc((n+2)*sizeof(int*));
        for(int i = 0; i < n+2; i++) 
            map[i] = (int *) calloc((m+2), sizeof(int));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                map[i+1][j+1] = grid[i][j];
            }
        }

        for(int i = 0; i < n+2; i++) {
            for(int j = 0; j < m+2; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }


        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++) {
                if(!map[i][j]) continue;
                num++;
                int cnt = 0;
                for(int k = 0; k < 4; k++) {
                    if(map[i+dx[k]][j+dy[k]]) cnt++;
                }
                if(cnt == 1) flag = true;

            }
        }

        if((num > 2 && flag) || num == 1) return 1;
        return 2;
    }
};