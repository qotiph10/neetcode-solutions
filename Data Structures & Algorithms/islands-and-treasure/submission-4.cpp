class Solution {
public:
    vector<vector<int>> dir = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};
    void dfs(vector<vector<int>>& grid , int d , int i , int j){
        if(grid[i][j] == -1){
            return;
        }
        if(grid[i][j] < d){
            return;
        }
        grid[i][j] = min(grid[i][j] , d);

        for(int x =0 ; x < 4 ; x++){
            int row , col;
            col = i + dir[x][0];
            row = j + dir[x][1];

            if(col >= 0 && row >= 0 && col < grid.size() && row < grid[0].size()){
                dfs(grid , d+1 , col , row);
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(!grid.size()){
            return;
        }

        for(int i =0 ; i<grid.size();i++){
            for(int j = 0 ; j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    dfs(grid , 0 , i , j);
                }
            }
        }
    }
};
