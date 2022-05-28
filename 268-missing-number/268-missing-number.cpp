class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        method1 : sort it 
                  keep a count and traverse the array while incrementing it
                  if you do not find the number == count, break and return
                  else return the count = n;
                  time = o(nlongn), space: o(1)
                  
        method2 : get and array of size n+1
                  travers the nums array and mark the nums[i] th index in 
                  the aux array as found using a boolean
                  lastly, travers the not found element from the aux array 
                  by traversing it again.
                  time = o(n) , space : o(n)
        method3 : using the given array as the aux, and change it -ve
                    time = o(N), space : O(1)
        
        method4 : getting the sum of elements and subtracting it from the sum
                    of first n natural numbers
                    time = o(N)
        */ 
        int n = nums.size();
        int sum = n*(n+1)/2, array_sum = 0;
        
        for(auto &i: nums) 
            array_sum += i;
        
        
        return sum-array_sum; 
    }
};