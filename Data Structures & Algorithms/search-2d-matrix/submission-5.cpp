class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rSize = matrix.size(),cSize = matrix[0].size();
        if(target > matrix[rSize-1][cSize-1]){
            cout <<"Target out of range ! max" << endl;
            return false;
        }

        int r = 0;
        while(r < rSize && target >= matrix[r][0]){
            r+=1;
        }
        r-=1;
        if(r == -1){
            cout <<"Target out of range ! min" << endl;
            return false;
        }
        cout << "r:" << r;
        if(matrix[r][0] == target){
            return true;
        }

        int left =0 , right = cSize -1, m;
        m = ((right - left) /2) + left;
        while(left <= right){
            if(target > matrix[r][m]){
                left = m +1;
            }
            else if(target < matrix[r][m]){
                right = m -1;
            }
            else{
                cout << " mid:" << m << endl;
                return true;
            }
            m = ((right - left) /2) + left;
        }
        cout << " mid:" << m << endl;
        cout <<"Target not found !" << endl;
        return false;
    }
};
