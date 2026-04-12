class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int l =0 , r = heights.size() -1;
        while(l < r){
            int c = (min(heights[l] , heights[r]) * (r - l ));
            cout<<"water:" << c << endl;
            ans = max(ans , c);
            if(heights[l] < heights[r]){
                l+=1;
            }
            else{
                r-=1;
            }
        }
        return ans;
    }
};
