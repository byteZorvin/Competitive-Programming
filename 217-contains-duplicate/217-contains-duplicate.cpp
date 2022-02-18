class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &i: nums) {
            if(!s.count(i)) s.insert(i);
            else return true;
        }
        return false;
    }
};