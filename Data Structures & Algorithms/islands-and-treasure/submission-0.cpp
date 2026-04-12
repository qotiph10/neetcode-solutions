class Solution {
public:
    vector<vector<int>> directions = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};
    void dfs(vector<vector<int>>& grid , int row , int col , int dis){
        cout << row << " " << col << "D: " << dis << endl;
        if(grid[row][col] > 0){
            grid[row][col] = min(dis , grid[row][col]);
        }
        
        for(int i = 0; i < 4 ;i++){
            int r , c;
            r = row + directions[i][0];
            c = col + directions[i][1];
            if(r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size()){
                if(grid[r][c] > dis + 1){
                    dfs(grid , r , c ,dis+1);
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty()){
            return;
        }
        for(int i =0 ; i<grid.size() ;i++){
            for(int j =0 ; j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    cout << " calling !!" << endl;
                    dfs(grid , i , j , 0);
                }
            }
        }
    }
};
