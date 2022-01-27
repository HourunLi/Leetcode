#include<bits/stdc++.h>
using namespace std;

//reverse thinking
class Solution {
  int m, n;
  int dx[4]= {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
public:
  void dfs(vector<vector<char>>& board, int x, int y) {
    if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] != 'O')
      return;
    
    board[x][y] = '-';
    for(int i = 0; i < 4; i++) {
      dfs(board, x + dx[i], y + dy[i]);
    }
    return;
  }

  void solve(vector<vector<char>>& board) {
    m = board.size(), n = board[0].size();
    for(int i = 0; i < n; i++) {
      dfs(board, 0, i);
      dfs(board, m-1, i);
    }
    for(int i = 1; i < m-1; i++) {
      dfs(board, i, 0);
      dfs(board, i, n-1);
    }

    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(board[i][j] == 'X') {
          continue;
        }else if(board[i][j] == '-') {
          board[i][j] = 'O';
        }else{
          board[i][j] = 'X';
        }
      }
    }
    return;
  }
};