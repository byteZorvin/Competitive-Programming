// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    vector<string> paths;
    vector<vector<bool>> vis;
    string currPath;
    
    private:
    bool issafe(int i, int j, vector<vector<int>> &m) {
        int n = m.size();
        return (i<n && j<n && i>=0 && j>=0) && m[i][j] == 1 && !vis[i][j];
    }
    
    private:
    void findPathRec(int i, int j, vector<vector<int>> &m) {
        int n = m.size();
        vis[i][j] = true;
        if(i == n-1 && j == n-1) {
            paths.push_back(currPath);
        }
        else {
            if(issafe(i, j+1, m)) {
                currPath.push_back('R');
                findPathRec(i, j+1, m);
                currPath.pop_back();
            }
            if(issafe(i+1, j, m)) {
                currPath.push_back('D');
                findPathRec(i+1, j, m);
                currPath.pop_back();
            }
            if(issafe(i-1, j, m)) {
                currPath.push_back('U');
                findPathRec(i-1, j, m);
                currPath.pop_back();
            }
            if(issafe(i, j-1, m)) {
                currPath.push_back('L');
                findPathRec(i, j-1, m);
                currPath.pop_back();
            }
        }
        vis[i][j] = false;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vis = vector<vector<bool>> (m.size(), vector<bool>(m.size(), false));
        if(issafe(0, 0, m))
            findPathRec(0, 0, m);
        return paths;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends