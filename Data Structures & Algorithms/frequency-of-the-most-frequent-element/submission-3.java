
class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        
        int l = 0, r = 0, ans = 1;
        long diff = 0;
        
        while (r < nums.length) {
            
            if (r > 0) {
                diff += (long)(nums[r] - nums[r - 1]) * (r - l);
            }
            
            while (diff > k) {
                diff -= (nums[r] - nums[l]);
                l += 1;
            }

            ans = Math.max(ans, r - l + 1);
            r += 1;
        }
        
        return ans;
    }
}