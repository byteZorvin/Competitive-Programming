class Solution {
private:
    static bool mycmp(vector<int>&a, vector<int>&b) {
        return abs(a[0] - a[1]) > abs(b[0] - b[1]);
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cityA = 0, cityB = 0, cst = 0, n = costs.size();
        n /= 2;
        sort(costs.begin(), costs.end(), mycmp);
        
        for(int i = 0; i<2*n; i++) {
            if(cityA<n && cityB<n) {
                if(costs[i][0] < costs[i][1]) {
                    cityA++;
                    cst += costs[i][0];
                } 
                else 
                    cst += costs[i][1], cityB++;
            }
            else if(cityA == n) {
                cityB++;
                cst += costs[i][1];
            }
            else {
                cityA++;
                cst += costs[i][0];
            }
        }
        return cst;
    }
};