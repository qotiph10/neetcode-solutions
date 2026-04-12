class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int , int> arr;
        vector<int> start_of_seq;
        for(int i =0 ; i< nums.size();i++){
            arr[nums[i]] +=1;
        }
        for(int i =0 ; i< nums.size();i++){
            if(arr[nums[i]-1] == 0){
                start_of_seq.push_back(nums[i]);
            }
        }

        int ans = 0;
        for(int i =0 ; i<start_of_seq.size();i++){
            int c = 1;
            while(arr[start_of_seq[i]+c]){
                c+=1;
            }
            ans = max(ans , c);
        }

        return ans;
    }
};
