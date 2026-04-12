class Solution {
public:
    int findMin(vector<int> &nums) {
        int l =0 , r = nums.size() -1 , m;
        m = ((r -l) / 2) + l;
        while(l < r){
            if(nums[m] > nums[r]){
                l = m +1;
            }
            else{
                r = m;
            }
            m = ((r -l) / 2) + l;
            cout << "L:" << l << " M:" << m << " R:" << r << endl;
        } 
        return nums[m];
    }
};
