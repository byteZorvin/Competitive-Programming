class Solution {
    static bool compare(pair<int, int> &a, pair<int, int> &b) {
        if(a.first == b.first) 
            return a.second < b.second;
        return a.first < b.first;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rows;
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i<m; i++) {
            int ones = 0;
            for(int j = 0; j<n; j++) {
                if(mat[i][j] == 1) 
                    ones++;
            }
            rows.push_back({ones, i});
        }
        sort(rows.begin(), rows.end(), compare);
        for(int i = 0; i<k; i++) {
            ans.push_back(rows[i].second);
        }
        return ans;
    }
};