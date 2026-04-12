class Solution {
public:
  int maxProfit(vector<int>& prices) {
        int profit = 0;
        int l = 0, r = 1;
        while(r < prices.size()){
            if(prices[l] < prices[r] ){
                if(prices[r] - prices[l] > profit){
                    profit = prices[r] - prices[l];
                }
                else {
                    r+=1;
                }
            }
            else{
                l = r;
                r = l + 1;
            }
        }
        return profit;
    }
};
