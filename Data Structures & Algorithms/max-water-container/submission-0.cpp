class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0 , j = heights.size() - 1;
        int ans = 0;
        while(i != j){
            int height =0, width =0, blocks = 0 , area = 0;
            height = min(heights[i] , heights[j]);
            width = j - i;
            area = (height * width);
            ans = max(ans , area);
            if(heights[i] < heights[j]){
                i++;
            }else{
                j--;
            }   
        }
        return ans;
    }
};
