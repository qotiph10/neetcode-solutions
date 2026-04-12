class Solution {
public:
    set<vector<int>> s;
    void backtrack(vector<int>& nums , int i , vector<int>sub){
        if(i >= nums.size()){
            s.insert(sub);
            return;
        }

        //no adding
        /* sort(sub.begin() , sub.end()); */
        backtrack(nums , i+1 , sub);
        s.insert(sub);

        //adding 
        sub.push_back(nums[i]);
        sort(sub.begin() , sub.end());
        backtrack(nums , i+1 , sub);
        s.insert(sub);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(!nums.size()){
            return {{}};
        }
        if(nums.size()==1){
            return {{},{nums[0]}};
        }

        vector<int>sub;
        backtrack(nums , 0 , sub);
        vector<vector<int>> ans;
        for(auto x: s){
            ans.push_back(x);
        }

        return ans;
    }
};
