class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int maxFreq = 0, maxEle, n = barcodes.size();
        unordered_map<int, int> freq;
        for(auto &e: barcodes) {
            maxFreq = max(maxFreq, ++freq[e]);
            maxEle = maxFreq == freq[e] ? e : maxEle;
        }
        vector<int> ans(n);
        int i = 0;
        while(maxFreq--) {
            if(i>=n) i = 1;
            ans[i] = maxEle;
            i += 2;
        }
        freq.erase(maxEle);
        for(auto &e: freq) {
            while(e.second--) {
                if(i>=n) i = 1;
                ans[i] = e.first;
                i += 2;
            }
        }
        return ans;
    }
};