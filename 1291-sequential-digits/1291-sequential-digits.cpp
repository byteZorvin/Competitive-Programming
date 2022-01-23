class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string seq = "123456789";
        vector<int> ans;
        string l = to_string(low), h = to_string(high);
        int szl = l.size(), szh = h.size();
        for(int s = szl; s<=szh; s++) {
            for(int i = 0; i<9-s+1; i++) {
                int num = stoi(seq.substr(i, s));
                if(num>=low && num<=high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};