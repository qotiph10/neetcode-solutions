class Solution {
public:
    bool isNotThere(vector<vector<int>> arr ,  vector<int>arr2){
        for(auto i : arr){
            if(i == arr2){
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0 ; i < nums.size() ;i++){
            for(int j = 0 ; j < nums.size() ;j++){
                for(int y = 0 ; y < nums.size() ;y++){
                    if(nums[i] + nums[j] + nums[y] == 0 && i != j && j != y && i != y){
                        vector<int> arr = {nums[i] , nums[j] , nums[y]};
                        sort(arr.begin() , arr.end());
                        if(isNotThere(ans , arr)){
                            ans.push_back(arr);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
