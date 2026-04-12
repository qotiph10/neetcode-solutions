class Solution {
public:
    void dp(int n , int sum , int &ans){
        if(n == sum){
            ans+=1;
            return;
        }
        else if(sum > n){
            return;
        }

        dp(n , sum + 1 , ans);
        dp(n , sum + 2 , ans);
    }
    int climbStairs(int n) {
        if(n == 0){
            return 0;
        }

        int ans = 0;
        dp(n , 0 , ans);
        return ans;
    }
};
