class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rmax(n);
        rmax[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--) 
            rmax[i] = max(rmax[i+1], height[i]);
        int lmaxi = 0, water = 0;
        for(int i = 0; i<n; i++) {
            lmaxi = max(lmaxi, height[i]);
            water += min(rmax[i], lmaxi) - height[i];
        }
        return water;
    }
};