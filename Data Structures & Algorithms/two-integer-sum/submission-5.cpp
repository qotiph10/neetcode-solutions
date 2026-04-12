class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> arr;
        for(int i =0 ; i <nums.size();i++){
            arr[nums[i]] = i;
        }
        for(int i = 0 ; i<nums.size();i++){
            int comp = target - nums[i];
            cout << nums[i] << " " << comp << endl;
            if(arr[comp] && arr[comp] != i){
                vector<int> ans;
                ans.push_back(min(i , arr[comp]));
                ans.push_back(max(i , arr[comp]));
                return ans;
            }
        }

        return{};
    }
};
