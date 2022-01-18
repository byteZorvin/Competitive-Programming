class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size(), planted = 0;
        for(int i = 0; i<sz; i++) {
            if(!flowerbed[i] && (i==0 || !flowerbed[i-1]) && (i==sz-1 || !flowerbed[i+1]))
                planted++, i++;
        }
        cout << planted;
        if(planted>=n) return 1;
        return 0;
    }
};