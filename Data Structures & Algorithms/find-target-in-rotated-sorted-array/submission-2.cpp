class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0 , r = nums.size()-1 , m;
        m = ((r-l)/2) + l;
        while(l<=r){
            if(nums[m] == target){
                return m;
            }
            else if(nums[r] == target){
                return r;
            }
            else if(nums[l] == target){
                return l;
            }

            if(nums[m] > nums[r]){
                if(target > nums[l] && target < nums[m]){
                    break;
                }
                else{
                    l = m + 1;
                }
            }
            else{
                if(target < nums[r] && target > nums[m]){
                    break;
                }
                else{
                    r = m - 1;
                }
            }
            m = ((r-l)/2) + l;
        }

        while(l<=r){
            if(target == nums[m]){
                return m;
            }
            else if(target > nums[m]){
                l = m +1;
            }
            else{
                r = m -1;
            }
            m = ((r-l)/2) + l;
        }
        
        return -1;
    }
};
