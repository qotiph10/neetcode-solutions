class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums , int target ,vector<int>&d  , int i){
        if(target < 0 || i > nums.size()){
            return;
        }
        
        if(target == 0){
            ans.push_back(d);
            return;
        }

        int temp = nums[i];
        d.push_back(temp);
        backtrack(nums , target - temp  , d , i+1);
        d.pop_back();
        while(temp == nums[i]){
            i+=1;
        }
        backtrack(nums , target  , d , i);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int>d;
        backtrack(candidates , target , d , 0);
        return ans;
    }
};
