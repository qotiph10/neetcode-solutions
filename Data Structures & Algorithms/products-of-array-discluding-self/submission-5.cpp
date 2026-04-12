class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n) , right(n) , ans(n , 1);
        int temp1 = 1, temp2 = 1;
        for(int i =0 ; i< n ;i++){
            temp1 *= nums[i];
            temp2 *= nums[n - i - 1];
            cout << temp1 << " " << temp2 << endl;
            right[i] = temp1;
            left[n - i - 1] = temp2;
        }
        for(int i =0 ; i< n ;i++){
            cout << "before ans :" << ans[i] << endl;
            int l = i -1 , r = i + 1;
            if(l >= 0){
                cout << " yes left !" << right[l];
                ans[i] *= right[l];
            }
            if(r < n){
                cout << " yes right !" <<left[r];
                ans[i] *= left[r];
            }
            cout << "after ans :" << ans[i] << endl;
        }

        return ans;
    }
};