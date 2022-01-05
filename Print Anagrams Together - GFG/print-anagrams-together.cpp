// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  private:
    bool checkAnagram(string &s, string &t) {
        unordered_map<char, int> mp;
        for(char &c : s) 
            mp[c]++;
        for(char &c : t) {
            if(mp.find(c) != mp.end()) {
                mp[c]--;
                if(mp[c] == 0)
                    mp.erase(c);
            }
            else return false;
        }
        return true;
    }
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size();
        vector<bool> ingrp(n, false);
        vector<vector<string>> ans;
        for(int i = 0; i<n; i++) {
            if(ingrp[i] == false) {
                ingrp[i] = true;
                ans.push_back({});
                ans.back().push_back(string_list[i]);
                
                for(int j = i+1; j<n; j++) {
                    if(ingrp[j] == false && checkAnagram(string_list[i], string_list[j])) {
                        ans.back().push_back(string_list[j]);
                        ingrp[j] = true;
                    }
                }
            }
        }
        return ans;
    }
};























// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends