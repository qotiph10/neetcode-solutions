class Solution {
public:
    void dp(vector<int> cost ,int i , int curCost , int &minCost){
        cout<<"i:"<<i<<endl;
        if(i >= cost.size()){
            minCost = min(minCost,curCost);
            return;
        }
        curCost+=cost[i];
        dp(cost , i + 1 , curCost, minCost);
        dp(cost , i + 2 , curCost, minCost);       
    }
    int minCostClimbingStairs(vector<int>& cost) {
        if(!cost.size()){
            return 0;
        }
        int minCost = INT_MAX;
        dp(cost , 0 , 0 , minCost);
        dp(cost , 1 , 0 , minCost);
        return minCost;
    }
};
