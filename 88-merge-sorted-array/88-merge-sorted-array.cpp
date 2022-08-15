class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        reverse(nums1.begin(), nums1.begin()+m);
        int i = m-1, j = 0, k = m+n-1;
        while(i>=0 && j<n) {
            if(nums1[i] < nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j++];
            }
        }
        while(i>=0) nums1[k--] = nums1[i--];
        while(j<n) nums1[k--] = nums2[j++];
        reverse(nums1.begin(), nums1.end());
    }
};