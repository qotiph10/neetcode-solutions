class Solution {
    public boolean isPerfectSquare(int num) {
        if(num == 1){
            return true;
        }
        long l = 1 , r = num/2  , mid = r/2;
        while(l <= r){
            if(mid * mid == num){
                return true;
            }
            else if(mid * mid > num){
                r = mid -1;
            }
            else{
                l = mid +1;
            }
            mid = (r - l) / 2 + l;
        }

        return false;
    }
}