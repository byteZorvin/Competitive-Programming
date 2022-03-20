class Solution {
     int helper(vector<int> &tops, vector<int> &bottoms, int a) {
         int n = tops.size(), ca = 0, cb = 0;
         for(int i = 0; i<n; i++) {
             if(tops[i] != a && bottoms[i] != a) return -1;
             if(tops[i] == a) ca++;
             if(bottoms[i] == a) cb++;
         }
         return min(n-ca, n-cb);
     }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = helper(tops, bottoms, tops[0]);
        if(ans != -1) return ans;
        return helper(tops, bottoms, bottoms[0]);
    }
};