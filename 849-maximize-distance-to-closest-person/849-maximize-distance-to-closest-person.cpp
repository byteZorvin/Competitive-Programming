class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), longestEmpty = 1;
        int len = 0, start = 0, end = 0;

        for(int i = 0; i<n; i++) {
            if(seats[i] == 0) {
                len++;
            }
            if(seats[i] and len) {
                if(len-i == 0) start = len;
                longestEmpty = max(longestEmpty, len);
                len = 0;
            }
        }
        if(len != 0) end = len;

        return max({(longestEmpty + 1)/2, start, end});
    }
};