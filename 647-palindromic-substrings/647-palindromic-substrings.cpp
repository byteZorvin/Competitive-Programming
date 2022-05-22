class Solution {
public:
int countSubstrings(string s) {
        int ans=0, n=s.size();
        for(int i=0; i<n; i++){
            int start = i, end=i;
            while(start>=0 and end<n and s[start--]==s[end++]){
                ans++;
            }
            start=i-1, end=i;
            while(start>=0 and end<n and s[start--]==s[end++]){
                ans++;
            }
        }
        return ans;        
    }
};