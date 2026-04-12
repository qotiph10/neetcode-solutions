class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 1 && nums[0] == target){
            int ans[] = {0,0};
            return ans;
        }
        else if(nums.length < 1){
            int ans[] = {-1,-1};
            return ans;
        }
        int l = 0 , r = nums.length -1, m = nums.length / 2;
        while(l < r){
            if(nums[m] < target){
                l = m + 1;
            }
            else if(nums[m] > target){
                r = m -1;
            }
            else{
                break;
            }
            m = (r - l) / 2 + l;
        }
        if(nums[m] != target){
            int ans[] = {-1,-1};
            return ans;
        }
        l = m; 
        r = m;
        while(l > 0 && nums[l-1] == target) l--; // Expand left
        while(r < nums.length - 1 && nums[r+1] == target) r++; // Expand right
        return new int[]{l, r};
    }
}