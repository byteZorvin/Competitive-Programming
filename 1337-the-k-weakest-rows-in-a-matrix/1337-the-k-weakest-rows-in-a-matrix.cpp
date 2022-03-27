class Solution {
private:
    int getStrength(vector<int>&a) {
        return upper_bound(a.begin(), a.end(), 1, greater<int>()) - a.begin();
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        int n = mat.size();
        for(int i = 0; i<n; ++i) {
            pq.push({getStrength(mat[i]), i});
            if(pq.size() > k) pq.pop(); 
        }
        vector<int> ans;
        while(pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};