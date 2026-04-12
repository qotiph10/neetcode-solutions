class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()){
            return 0;
        }

        sort(nums.begin(),nums.end());
        int ans = 1 , c = 1;
        for(int i =0 ; i< nums.size() ;i++){
            if(nums[i] == nums[i+1]){
                continue;
            }
            else if(nums[i]  + 1 != nums[i+1]){
                c = 0;
            }
            c+=1;
            cout << "c:" << c << " i:" << i<<endl;
            ans = max(ans , c);
        }
        return ans;
    }
};