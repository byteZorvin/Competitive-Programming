class Solution {
private:
    bool CanEat(vector<int> &piles, int AvalTime, int speed) {
        long long time = 0;
        for(int i = 0; i<piles.size(); i++) {
            time += (piles[i] + speed -1)/speed;
            if(time>AvalTime) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size();
        long long low = 1, high = 1e9 + 10, minSpeed = 1e4 + 10;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(CanEat(piles, h, mid))
                minSpeed = mid, high = mid-1;
            else
                low = mid+1;
        }
        return minSpeed;
    }
};