class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        unordered_map<int, vector<int>> m;
        for(int i = 0; i<n; i++){
            m[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        int step = 0;
        while(!q.empty()){
            step++;
            int size = q.size();
            for(int i = 0; i< size; i++){
                int x = q.front();
                q.pop();
                
                // jump to x+1
                if(x+1 < n && m.count(arr[x+1])){
                    if(x+1 == n-1) 
                        return step;
                    q.push(x+1);
                }
                // jump to x-1
                if(x-1 >= 0 && m.count(arr[x-1])){
                    q.push(x-1);
                }
                // check for arr[x] == arr[x]
                if(m.count(arr[x])){
                    for(auto a : m[arr[x]]){
                        if(a == n-1) return step;
                        q.push(a);
                    }
                }
                m.erase(arr[x]);
            }
        }
        return step;
    }
};