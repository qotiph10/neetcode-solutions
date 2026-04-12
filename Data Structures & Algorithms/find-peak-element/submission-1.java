class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0 , r = nums.length -1 , mid = r /2;
        while(l < r){
            if(mid + 1 < nums.length && mid - 1 >= 0){
                if(nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid]){
                    return mid;
                }
                else if(nums[mid+1] > nums[mid-1]){
                    l = mid +1;
                }   
                else{
                    r = mid -1;
                }
            }
            else if(mid + 1 < nums.length && nums[mid] > nums[mid+1] || mid - 1 >= 0 && nums[mid] > nums[mid-1]){
                return mid;
            }
            else{
                if(mid + 1 < nums.length){
                    l = mid +1;
                }
                else{
                    r = mid -1;
                }
            }
            mid = (r - l) / 2 + l;
        }
        System.out.print("out of binary!");
        return mid;
    }
}