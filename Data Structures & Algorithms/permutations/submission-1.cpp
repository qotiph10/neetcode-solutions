class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> arr , vector<int> per){
        if(arr.size() == 1){
            per.push_back(arr[0]);
            ans.push_back(per);
            return;
        }

        for(int i = 0 ; i<arr.size();i++){
            /* cout << "adding:"<<arr[i]<<endl; */
            int temp = arr[i];
            arr.erase(arr.begin() + i);
            per.push_back(temp);
            backtrack(arr , per);
            /* cout << "Sending: {";
            for(auto x:arr){
                cout << x << ",";
            }
            cout<<"}\n"; */

            arr.insert(arr.begin() + i , temp);
            per.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(!nums.size()){
            return {{}};
        }
        if(nums.size() == 1){
            return {{nums[0]}};
        }

        vector<int> arr(nums);
        vector<int> per;
        for(int i =0 ; i < arr.size() ;i++){
            /* cout <<"i:"<<i << " adding:"<<arr[i]<<endl; */
            int temp = arr[i];
            arr.erase(arr.begin() + i);
            per.push_back(temp);
            backtrack(arr , per);
            /* cout << "Sending: {";
            for(auto x:arr){
                cout << x << ",";
            }
            cout<<"}\n"; */

            arr.insert(arr.begin() + i , temp);
            per.pop_back();
        }

        return ans;
    }
};
