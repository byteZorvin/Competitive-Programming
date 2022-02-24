class Solution {
    int old;
private:
    bool valid(int x, int y, vector<vector<int>> &image) {
        int m = image.size(), n = image[0].size();
        return x>=0 && x<m && y>=0 && y<n && image[x][y] == old;
    }
private:
    void dfs(vector<vector<int>> &image, int x, int y, int newColor) {
        if(valid(x, y, image)) {
            image[x][y] = newColor;
            dfs(image, x-1, y, newColor);
            dfs(image, x+1, y, newColor);
            dfs(image, x, y-1, newColor);
            dfs(image, x, y+1, newColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        old = image[sr][sc];
        if(old != newColor)
            dfs(image, sr, sc, newColor);
        return image;
    }
};