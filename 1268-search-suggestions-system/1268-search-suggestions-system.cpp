class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        auto it = products.begin();
        sort(it, products.end());
        string prefix;
        for(auto &c: searchWord) {
            prefix += c;
            it = lower_bound(it, products.end(), prefix);
            vector<string> suggested;
            for(int i = 0; i<3 && it+i<products.end(); i++) {
                string &s = *(it+i);
                if(s.find(prefix)) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};