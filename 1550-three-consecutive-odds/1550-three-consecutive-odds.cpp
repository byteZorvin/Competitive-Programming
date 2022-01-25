class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int current = 0;
        for(int i = 0; i<arr.size(); i++) {
            if(arr[i]%2) {
                current++;
                if(current == 3) return true;
            }
            else current = 0;
        }
        return false;
    }
};