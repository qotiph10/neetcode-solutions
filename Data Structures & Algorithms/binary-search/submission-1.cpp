class Solution {
public:
    int search(vector<int>& nums, int target) {
    int l , r , m;
    l = 0; r = nums.size() - 1; 
    m = l + (r - l) / 2;
    while(l <= r){
         if(nums[m] > target){
             r = m - 1;
             m = l + (r - l) / 2;
         }
         else if(nums[m] < target){
             l = m + 1;
             m = l + (r - l) / 2;
         }
         else{
             return m;
         }
    } 
    return -1;
 }
};
