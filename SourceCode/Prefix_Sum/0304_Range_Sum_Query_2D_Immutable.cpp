class NumMatrix {
private:
  int **arr;
public:
  NumMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size(), m =  matrix[0].size();
    arr = new int*[n+1];
    for(int i = 0; i <=n; i++) {
      arr[i] = new int[m+1];
    }
    for(int i = 0; i < n+1; i++) {
      for(int j = 0; j < m+1; j++) {
        if(i == 0 || j == 0) {
          arr[i][j] = 0;
          continue;
        }
        arr[i][j] = matrix[i-1][j-1];
        arr[i][j] += arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
      }
    }
    return;
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    return arr[row2+1][col2+1] - arr[row2+1][col1] - arr[row1][col2+1] + arr[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */