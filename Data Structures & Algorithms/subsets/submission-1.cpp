class Solution {
public:   
    void backtrack(vector<int>& nums , int i , vector<int> arr , vector<vector<int>> &ans){
        if(i < nums.size()){
            backtrack(nums,i+1,arr,ans);
            arr.push_back(nums[i]);
            backtrack(nums,i+1,arr,ans);
        }
        else{
            ans.push_back(arr);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(!nums.size()){
            return {{}};
        }
        vector<int> arr;
        vector<vector<int>> ans; 
        backtrack(nums , 0 , arr , ans);
        return ans;
    }
};
