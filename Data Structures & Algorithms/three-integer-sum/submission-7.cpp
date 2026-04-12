class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> setAns;
        int i = 0 ;
        while(nums[i] <= 0){
            int l = 0 , r = nums.size() -1;
            int n1 , n2 ,n3;
            n1 = nums[i];
            while(l < r){
                vector<int> temp;
                n2 = nums[l];
                n3 = nums[r];
                if(r == i){
                    r-=1;
                    continue;
                }
                else if(l ==i){
                    l+=1;
                    continue;
                }
                
                if(n1 + n2 + n3 > 0){
                    r-=1;
                }
                else if(n1 + n2 + n3 < 0){
                    l+=1;
                }
                else{
                    temp.push_back(n1);
                    temp.push_back(n2);
                    temp.push_back(n3);
                }

                if(temp.size()){
                    sort(temp.begin() ,  temp.end());
                    setAns.insert(temp);
                    l+=1;
                    r-=1;
                }
            }
            i+=1;
        }

        for(auto x:setAns){
            ans.push_back(x);
        } 
        return ans;
    }
};
