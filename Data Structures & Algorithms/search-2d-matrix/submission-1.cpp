class Solution {
public:
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int col = 0 , l , r , mid;
    while(matrix[col][0] < target && col < n){
        col++;
        if(col == n){
            col -=1;
            break;
        }
    }
    if(matrix[col][0] == target){
        return true;
    }
    else if(matrix[col][0] > target){
        col -= 1;
        if(col < 0){
            return false;
        }   
    }
    
    l = 0; r = m -1 ;
    mid = l + (r - l) / 2;
    while(l <= r){
        if(matrix[col][mid] == target){
            return true;    
        }
        else if(matrix[col][mid] < target){
            l = mid + 1;
            mid = l + (r - l) / 2;
        }
        else{
            r = mid - 1;
            mid = l + (r - l) / 2;
        }
    }
    return false;
}
};
