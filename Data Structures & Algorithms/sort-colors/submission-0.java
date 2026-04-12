class Solution {
    public void sortColors(int[] nums) {
        for(int i =0 ; i<nums.length-1;i++){
            if(nums[i+1] < nums[i]){
                int j = i;
                while(j >= 0 && nums[j+1] < nums[j]){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                    j-=1;
                }
            }
        }
    }
}