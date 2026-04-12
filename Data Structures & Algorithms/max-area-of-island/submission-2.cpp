class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& grid , int i , int j){
        if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size()){
            if(grid[i][j] == 1){
                grid[i][j] = 0;
                return 1 + 
                dfs(grid , i + dir[0][0], j + dir[0][1]) + 
                dfs(grid , i + dir[1][0], j + dir[1][1]) + 
                dfs(grid , i + dir[2][0], j + dir[2][1]) + 
                dfs(grid , i + dir[3][0], j + dir[3][1]);
            }
        }
        return 0;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(!grid.size()){
            return 0;
        }

        int ans = 0;
        for(int i =0 ; i< grid.size();i++){
            for(int j =0 ; j< grid[0].size();j++){
                if(grid[i][j] == 1){
                    ans = max(dfs(grid,i,j) , ans);
                }
            }
        }
        return ans;
    }
};
