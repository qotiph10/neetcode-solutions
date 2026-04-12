class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int , bool> mp;
        vector<int> start;
        for(int i =0 ; i<nums.size();i++){
            mp[nums[i]] = true;
        }

        for(int i =0 ; i<nums.size();i++){
            int before = nums[i] -1;
            if(!mp[before]){
                start.push_back(nums[i]);
            }
        }

        int ans = 0 , c =1;
        for(auto i : start){
            int after = i +1;
            while(mp[after]){
                c+=1;
                after+=1;
            }
            ans = max(ans , c);
            c =1;
        }

        return ans;
    }
};
