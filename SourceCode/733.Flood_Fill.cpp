class Solution {
private:
    int dx[4]= {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        int curColor = image[sr][sc];
        if(curColor == newColor) return image;

        queue<pair<int, int>> q;
        q.push_back(sr, sc);

        while(!q.empty()) {
            auto head = q.front(); q.pop();
            int x = head.first, y = head.second;
            image[x][y] = newColor;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >=0 && ny >=0 && nx < n && ny < m && image[nx][ny] == curColor) {
                    q.push_back(nx, ny);
                }
            }
        }
        return image;
    }
};