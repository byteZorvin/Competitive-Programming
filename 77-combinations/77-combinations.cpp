class Solution {
public:
    vector<vector<int>> ans;
    void s(vector<int>& v, int n, int k, int i){
        if(i>n) return ;
        s(v, n, k, i+1);
        v.push_back(i);
        s(v, n, k, i+1);
        if(v.size()==k){
            ans.push_back(v);
        }
        v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        s(v, n, k, 1);
        return ans;
    }
};