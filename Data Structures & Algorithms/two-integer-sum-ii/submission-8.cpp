class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int , int> arr;
        for(int i =0 ; i<numbers.size() ;i++){
            arr[numbers[i]] =  i;  
        }
        for(auto i : arr){
            int x;
            if(i.first > target){
                    x = i.first - target;
                    if(arr.count(-x)){
                        return { min(i.second +1, arr[-x]+1), max(i.second+1 , arr[-x]+1)};
                    }
                }
                else if(i.first < target){
                    x = target - i.first;
                    if(arr.count(x)){
                        return { min(i.second +1, arr[x]+1), max(i.second+1 , arr[x]+1)};
                    }
                }
                else{
                    x = 0;
                    if(arr.count(x)){
                        return { min(i.second +1, arr[x]+1), max(i.second+1 , arr[x]+1)};
                    }
                }
        }
        return {0 , 0};
    } 
};
