class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 2){
            if(prices.size() == 2){
                return prices[1] - prices[0] >= 0 ? prices[1] - prices[0] : 0;
            }
            else{
                return 0;
            }
        }

        int l = 0 , r = 1;
        /* int MIN = prices[l];
        int MAX = prices[R]; */
        int ans = 0;
        while(r < prices.size()){
            if(prices[r] < prices[l]){
                l = r;
            }
            ans = max(prices[r] - prices[l] , ans);
            r+=1;
        }
        return ans;
    }
};
