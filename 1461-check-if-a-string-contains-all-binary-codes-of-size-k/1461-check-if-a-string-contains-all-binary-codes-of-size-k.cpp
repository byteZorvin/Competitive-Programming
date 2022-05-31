class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n<(1<<k)+k-1) return false;
        
        int need = 1<<k;
        int allOne = need-1;
        int hashValue = 0;
        vector<bool>found(need, false);
        
        for(int i = 0; i<n; i++) {
            hashValue = ((hashValue<<1) & allOne | s[i] - '0');
            if(!found[hashValue])
                need--, found[hashValue] = true;
            if(need == 0)
                return true;
        }
        return false;
    }
};