class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        int peak = 0;
        for(int i = 0; i<n; i++) {
            if(arr[i+1] > arr[i])
                peak++;
            else break;
        }
        if(peak==0 || peak == n-1) return false;
        for(int i = peak; i<n-1; i++) {
            if(arr[i] > arr[i+1]) 
                peak++;
            else return false;
        }
        
        return true;
    }
};