/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
return nums.reduce((prev, curr) => prev = prev^curr,-0)
};