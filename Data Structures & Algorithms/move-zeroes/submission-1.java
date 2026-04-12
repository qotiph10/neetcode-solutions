class Solution {
    public void moveZeroes(int[] nums) {
        int l = 0 , r = 0;
        while(r < nums.length && l < nums.length){
            if(nums[l] != 0){
                while(l < nums.length&&nums[l] != 0){
                    l+=1;
                }
            }
            if(nums[r] != 0 && r > l){
                nums[l] = nums[r];
                nums[r] = 0;
            }
            r+=1;
        } 
    }
}