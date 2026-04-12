class Solution {
public:
    vector<vector<int>> directions = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};
    void bfs(vector<vector<int>>& grid , int r , int c){
        queue<vector<int>> q;
        q.push({r , c});
        int steps = 1;
        while(!q.empty()){
            for(int i = q.size()-1;i>=0;i--){
                vector<int> point = q.front();
                q.pop();
                if(point.size()){
                    for(int i = 0 ; i< 4 ;i++){
                        int row = point[0] + directions[i][0] , col = point[1] + directions[i][1];
                        if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size()){
                            if(steps < grid[row][col]){
                                grid[row][col] = steps;
                                q.push({row , col});
                            }
                        }
                    }
                }
            }
            steps+=1;
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty()){
            return;
        }
        for(int i =0 ; i < grid.size() ;i++){
            for(int j = 0 ; j<grid[0].size() ;j++){
                if(grid[i][j] == 0){
                    bfs(grid , i , j);
                }
            }
        }
    }
};
