class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length <= 1){
            return 0;
        }

        int index = 0 , profit = 0;
        for(int i =1 ; i<prices.length ;i++){
            if(prices[i-1] > prices[i]){
                profit += prices[i-1] - prices[index];
                index = i;
                //System.out.println("p: "+profit);
            }
        }
        if(prices[index] < prices[prices.length -1]){
            profit += Math.abs(prices[index] - prices[prices.length -1]);
        }
        return profit;
    }
}