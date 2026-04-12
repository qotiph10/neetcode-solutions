class Solution {
public:
    bool backtrack(vector<vector<char>> board, string word , int cur , int i  , int j ){
        if(cur == word.length()){
            return true;
        }

        int rowSize , colSize;
        rowSize = board.size();
        colSize = board[0].size();

        int left , right , top , bottom;
        left = j-1;
        right = j+1;
        top = i-1;
        bottom = i+1;
        
        board[i][j] = '.';
        if((left >= 0 && left < colSize) && board[i][left] == word[cur]){
            bool ans = backtrack(board , word , cur+1, i , left);
            if(ans){
                return true;
            } 
        }
        if((right >= 0 && right < colSize) && board[i][right] == word[cur]){
            bool ans = backtrack(board , word , cur+1, i , right);
            if(ans){
                return true;
            } 
        }
        if((top >= 0 && top < rowSize) && board[top][j] == word[cur]){
            bool ans = backtrack(board , word , cur+1, top , j);
            if(ans){
                return true;
            } 
        }
        if((bottom >= 0 && bottom < rowSize) && board[bottom][j] == word[cur]){
            bool ans = backtrack(board , word , cur+1, bottom , j);
            if(ans){
                return true;
            } 
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rowSize , colSize;
        rowSize = board.size();
        colSize = board[0].size();
        for(int i =0 ; i<rowSize;i++ ){
            for(int j = 0 ; j< colSize;j++){
                if(board[i][j] == word[0]){
                    cout << "i:"<<i<<" j:"<<j<<endl;
                    bool ans = backtrack(board , word , 1, i , j);
                    if(ans){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
