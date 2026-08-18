class Solution {
    public void rotate(int[] nums, int k) {
        int moveLen = k % nums.length;
        if(moveLen == 0 || nums.length <= 1){
            return;
        }
        
        int c = 0;
        int start = 0;

        while(c < nums.length){
            int index = start;
            int temp = nums[index];
            
            while(true) {
                int iMove = (index + moveLen) % nums.length;
                
                int temp2 = nums[iMove];
                nums[iMove] = temp;
                temp = temp2;
                
                index = iMove;
                c += 1;
                
                if(index == start){
                    break; 
                }
            }
            start++; 
        }
    }
}