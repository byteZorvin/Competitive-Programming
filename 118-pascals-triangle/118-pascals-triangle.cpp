class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i = 1; i<numRows; i++) {
            vector<int> row {1};
            int rowEleCnt = ans[i-1].size();
            for(int j = 0; j<rowEleCnt-1; j++) {
                row.push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            row.push_back(1);
            ans.push_back(row);
        }
        return ans;
    }
};